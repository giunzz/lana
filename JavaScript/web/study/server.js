const express = require('express'),
    app = express();
const defaultPort = 3000,
    indexFile = "index.html";
var fs = require("fs");

app.use(express.static('public'));

app.get('/index.html', function(req, res){
    res.sendFile(__dirname + "/" + indexFile);
})

app.get('/process', function (req, res) {
    response = {
        fir:req.query.first,
        sec:req.query.second
    };
    console.log(response);
    // fs.write('/public/log.json', JSON.stringify(response));
    res.end(JSON.stringify(response));
})

var server = app.listen(defaultPort, function () {;
    console.log("http://localhost:%s", server.address().port);
})