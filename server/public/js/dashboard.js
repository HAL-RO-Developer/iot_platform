$(function () {
    if (cookies.hasItem('token')) {
        $('.default').css('display', 'block');
        $('.contents').css('display', 'none');
    } else {
        location.href = '/';
    }

});

function signout() {
    $(function () {
        if (!confirm('サインアウトしますか?')) {
            /* キャンセルの時の処理 */
            return false;
        } else {
            /*　OKの時の処理 */
            cookies.removeItem('token');
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
        $.each(data['devices'], function (index, elem) {
            $('#device-list').append(
                $('<tr></tr>')
                .append($('<th></th>').text(index + 1))
                .append($('<td></td>').text(elem.DeviceName))
                .append($('<td></td>').text(elem.DeviceID))
                .append($('<td></td>').text(elem.Mac))
                .append($('<td></td>').text(elem.Pin))
                .append($('<td></td>').text(!(elem.Mac == '')))
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

$(function () {
    $('#create-device-button').on('click', function () {
        $.ajax({
                url: '/api/device',
                type: 'post',
                dataType: 'json',
                timeout: 10000,
                headers: {
                    'Authorization': cookies.getItem('token')
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
        alert($("#pin-code").val());
    });
});

function getDevice() {
    return $.ajax({
        url: '/api/device',
        type: 'get',
        dataType: 'json',
        timeout: 10000,
        headers: {
            'Authorization': cookies.getItem('token')
        },
        data: {
            'device_name': $('#device-name').val()
        }
    })
}
