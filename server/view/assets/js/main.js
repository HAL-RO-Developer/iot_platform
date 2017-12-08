function viewSignIn(){
    $(function(){
        $(".sign-in").css("display","block");
        $(".sign-up").css("display","none");
    });
}

function viewSignUp(){
    $(function(){
        $(".sign-in").css("display","none");
        $(".sign-up").css("display","block");
    });
}
