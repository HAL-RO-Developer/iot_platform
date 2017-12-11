$(function () {

    if ($.cookie('token') == '') {
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
            $.removeCookie('token');
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
    var $response = getDevice();
    console.log('response',$response);
}

$(function () {
    $('#create-device-button').on('click', function () {
        $.ajax({
            url: '/api/device',
            type: 'post',
            dataType: 'json',
            timeout: 10000,
            headers: {
                'Authorization': $.cookie('token')
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
            'Authorization': $.cookie('token')
        },
        data: {
            'device_name': $('#device-name').val()
        }
    })
}

getDevice().done(function (data) {
   // 成功時
})
    .fail(function (jqXHR, textStatus, errorThrown) {
        // 失敗時
        console.log(jqXHR);
        console.log(textStatus);
        console.log(errorThrown);
        $errMsg = jqXHR['responseJSON']['err']
        alert($errMsg);
    });

