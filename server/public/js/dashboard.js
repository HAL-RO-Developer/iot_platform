$(function () {
    if( $.cookie('token') == null ){
        location.href = '/';
    }
});

function signout(){
    $(function(){
        if(!confirm('サインアウトしますか?')){
            /* キャンセルの時の処理 */
            return false;
        }else{
            /*　OKの時の処理 */
            $.removeCookie( 'token' );
            location.href = '/';
        }
    });
}

$(function(){
    $('#create-device-button').on('click',function(){
        $.ajax({
            url: '/api/device',
            type: 'post',
            dataType: 'json',
            timeout: 10000,
            headers: {
                'Authorization': $.cookie('token')
            }
        })
            .done(function(data){
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

$(function() {
    $("#copy-pin-code").on("click", function() {
      alert($("#pin-code").val());
    });
  });
  