function showSignIn(){
    $(function(){
        $('#signin').css('display','block');
        $('#signup').css('display','none');
    });
}

function showSignUp(){
    $(function(){
        $('#signin').css('display','none');
        $('#signup').css('display','block');
    });
}

$(function(){
    showSignIn();
});

$('.signin-form').submit(function(event){
    event.preventDefault();

    var $form = $(this);

    var $button = $form.find('button');

    $.ajax({
        url:       $form.attr('action'),
        type:      $form.attr('methode'),
        data:      $form.selialize(),
        timeout:   1000,

        beforeSend: function(xhr, settings){
            $button.attr('disabled', true);
        },

        complete:   function(xhr, textStatus){
            $button.attr('disabled', false);
        },

        success:    function(xhr, textStatus, result){
            $form[0],reset();
        },

        error:      function(xhr, textStatus, error){
            aleart('NG');
        }

    });

});
