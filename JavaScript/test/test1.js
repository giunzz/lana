var express = require('express');
var app = express();
var path = require ('path');
app.set('view engine', 'pug');
app.set('views', path.join(__dirname + '\\views'));

app.get('/', function (req, res) {
    res.render('index')
});

app.listen(3000);