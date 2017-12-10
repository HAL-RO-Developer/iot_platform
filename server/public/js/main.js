function showSignIn() {
    $(function () {
        $('#signin').css('display', 'block');
        $('#signup').css('display', 'none');
    });
}

function showSignUp() {
    $(function () {
        $('#signin').css('display', 'none');
        $('#signup').css('display', 'block');
    });
}

$(function () {
    showSignIn();
});

$(function () {
    $('.js-show').each(function () {
        var $pass = $(this).find('.js-pass');
        var $input = $(this).find('.js-check');
        $input.change(function () {
            if ($(this).prop('checked')) {
                $pass.attr('type', 'text');
            } else {
                $pass.attr('type', 'password');
            }
        });
    });
});

$(function () {
    $('.signin-form').on('submit', function (event) {
        event.preventDefault();
        $form = $(this)
        $name = $('[name="name"]').val()
        $.ajax({
            url: $form.attr('action'),
            type: $form.attr('method'),
            data: $form.serialize(),
            dataType: 'json',
            timeout: 10000,
        })
            .done(function (data) {
                console.log(data);
                console.log(data['token']);
                $token = data['token'];
                $.cookie('token', $token, { expires: 1 })
                location.href = '/user/' + $name + '/dashboard';   // 仮
                // postDashboard($name);
            })
            .fail(function (XMLHttpRequest, textStatus, errorThrown) {
                console.log(XMLHttpRequest);
                console.log(textStatus);
                console.log(errorThrown);
                $errMsg = XMLHttpRequest['responseJSON']['err']
                alert($errMsg);
            });
    });
});

function postDashboard(name) {
    $(function () {
       $.post('/user/' + name + '/dashboard');
    });
}
