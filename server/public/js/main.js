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
        $.ajax({
            url: $(this).attr('action'),
            type: $(this).attr('method'),
            data: $(this).serialize(),
            timeout: 10000,
        })
            .done(function (data) {
                console.log(data)
                console.log(data['token'])
                $.cookie('token', data['token'], { expires: 1 })
                location.href = '/dashboard';   // 仮
            })
            .fail(function (XMLHttpRequest, textStatus, errorThrown) {
                console.log(XMLHttpRequest)
                console.log(textStatus)
                console.log(errorThrown)
                alert(XMLHttpRequest['responseJSON']['err'])
            });
    });
});
