(function(ext) {
  // Extension が終了するときに呼ばれる
  ext._shutdown = function() {};
  
  // Extension の状態を返す
  ext._getStatus = function() {
    return {status: 2, msg: 'Ready'};
  };
  
  /*
     signUp
  */
  ext.signUp = function(id, password) {
    var url= 'http://fetch-api-sample.azurewebsites.net/api/200';
    $.ajax({
        url: hostUrl,
        type:'GET',
        dataType: 'json',
        data : 'name='+id+'&password='+password,
        timeout:10,
    }).done(function(data,textSize,jqXHR){
      alert(JSON.stringify(data));
    }).fail(function(jqXHR, textSize, errorThrown){
      alert(JSON.stringify(jqXHR));
    })
  };

  /*
     signIn
  */
  ext.signIn = function(id, password) {
    var url= 'http://fetch-api-sample.azurewebsites.net/api/200';
    fetch(url)
    .then(function(data) {
      var message = ([
        '成功ハンドラで処理されました。',
        'data: ' + JSON.stringify(data, null, '  '),
      ]).join('\n');
      alert(message);
    });
  };
  
  // ブロックをどういう風に表示するかを書きます
  // ここの書き方は結構難しいので今は説明しません
  var descriptor = {
    blocks: [
      ['w','SignUp : UserID %s Password %s', 'signUp'],
      ['w','SignIn : UserID %s Password %s', 'signIn'],
    ]
  };
  
  // Scratch に作ったブロックを登録します
  ScratchExtensions.register('IoT Platform', descriptor, ext);
})({});
