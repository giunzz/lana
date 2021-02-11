var express = require('express');
var app = express();

// var things = require('./things')

// var express = require('express');
// var app = express();
// var path = require ('path');
// app.set('view engine', 'pug');
// app.set('views', path.join(__dirname + '\\views'));

// app.use(function(req, res, next){
//     console.log("START");
//     // next();
// });

app.get('/', function(req, res){
    res.send("Hello world!");
});

// app.get('/dynamic_view', function(req, res){
//     res.render('dynamic', {
//         name: "TutorialsPoint", 
//         url:"http://www.tutorialspoint.com"
//     });
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