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
