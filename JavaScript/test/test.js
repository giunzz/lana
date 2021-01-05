var express = require('express');
var app = express();

// var things = require('./things')

app.set('view engine', 'pug');
app.set('views', './views');

// app.use(function(req, res, next){
//     console.log("START");
//     // next();
// });

app.get('/first_template', function(req, res){
    res.render('first_view');
});

// app.get('/', function(req, res){
//     res.send("Hello world!");
// });

// app.all('/', function(req, res){
//     res.send("Post request detected");
// });

// app.get('/rg/:id', function(req, res){
//     var tmp = req.params.id;
//     // console.log(tmp.length);
//     res.send('id: ' + req.params.id);
// })

// // app.get('/things/abc', function(req, res){
// //     res.send('ngu');
// // });

// app.use('/things', things);

// app.use('/abcd' ,function(req, res, next){
//     console.log('Received at: ' + Date.now());
//     // function/route handle.
//     next();
//     // res.send('abc');
// });

// app.post('/abcd', function(req, res){
//     res.send('abc2');
// });

// app.get('/abcd', function(req, res){
//     res.send('abc1');
// });

app.listen(3000);