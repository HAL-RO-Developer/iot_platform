$(function() {
    showSignIn();
});

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
            timeout: 10000
        })
            .done(function (data) {
                console.log(data);
                $token = data['token'];
                cookies.setItem('token', $token);
                location.href = '/user/' + $name + '/dashboard';
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

