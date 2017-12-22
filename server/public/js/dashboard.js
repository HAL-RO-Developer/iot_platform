$(function () {
    if (localStorage.getItem('token') == null) {
        location.href = '/';
    } else {
        $('.default').css('display', 'block');
        $('.contents').css('display', 'none');
    }

});

function signout() {
    $(function () {
        if (!confirm('サインアウトしますか?')) {
            /* キャンセルの時の処理 */
            return false;
        } else {
            /*　OKの時の処理 */
            localStorage.removeItem('token');
            location.href = '/';
        }
    });
}

function showCreateDevice() {
    $('.default').css('display', 'none');
    $('.contents').css('display', 'none');
    $('#create-device').css('display', 'block');
}

function showListDevice() {
    $('.default').css('display', 'none');
    $('.contents').css('display', 'none');
    $('#get-device').css('display', 'block');
    getDevice().done(function (data) {
        console.log(data);
        $('#device-list .device').remove();
        $.each(data['devices'], function (index, elem) {
            $('#device-list').append(
                $(`<tr class="device" data-toggle="modal" data-target="#device-context-menu" data-whatever=${elem.DeviceID}></tr>`)
                    .append($('<th></th>').text(index + 1))
                    .append($('<td class="device-name"></td>').text(elem.DeviceName))
                    .append($('<td class="device-id"></td>').text(elem.DeviceID))
                    .append($('<td class="mac"></td>').text(elem.Mac))
                    .append($('<td class="pin"></td>').text(elem.Pin))
                    .append($('<td class="activate"></td>').text(!(elem.Mac == '')))
            );
        });
    }).fail(function (jqXHR, textStatus, errorThrown) {
        console.log(jqXHR);
        console.log(textStatus);
        console.log(errorThrown);
        $errMsg = jqXHR['responseJSON']['err']
        alert($errMsg);
    });
}

$(function(){
    $('#device-context-menu').on('show.bs.modal', function(event){
        var device = $(event.relatedTarget);
        var recipient = device.data('whatever');
        localStorage.setItem('selected-device', recipient );
    });
});


$(function () {
    $('#create-device-button').on('click', function () {
        $.ajax({
            url: '/api/device',
            type: 'post',
            dataType: 'json',
            timeout: 10000,
            headers: {
                'Authorization': localStorage.getItem('token')
            },
            data: {
                'device_name': $('#device-name').val()
            },
        })
            .done(function (data) {
                $pin = data['pin'];
                $('#pin-code').val($pin)
            })
            .fail(function (jqXHR, textStatus, errorThrown) {
                console.log(jqXHR);
                console.log(textStatus);
                console.log(errorThrown);
                $errMsg = jqXHR['responseJSON']['err']
                alert($errMsg);
            });
    });
});

$(function () {
    $("#copy-pin-code").on("click", function () {
        
    });
});

$(function () {
    $("#copy-device-id").on("click", function () {
        if(copyTextToClipboard(localStorage.getItem('selected-device'))){
            alert('Copy successful!');
        }else{
            alert('Copy Error!');
        }
    });
});

$(function () {
    $("#remove-device").on("click", function () {
        
    });
});

function copyTextToClipboard(textval){
    var copyForm = document.createElement("textarea");
    copyForm.textContent = textval;

    var bodyElm = document.getElementsByTagName("body")[0];
    bodyElm.appendChild(copyForm);

    copyForm.select();
    var retVal = document.execCommand('copy');
    bodyElm.removeChild(copyForm);
    return retVal;
}

function getDevice() {
    return $.ajax({
        url: '/api/device',
        type: 'get',
        dataType: 'json',
        timeout: 10000,
        headers: {
            'Authorization': localStorage.getItem('token')
        },
        data: {
            'device_name': $('#device-name').val()
        }
    })
}
