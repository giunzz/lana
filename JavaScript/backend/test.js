const express = require('express')
const app = express()
var port = 3000

// This responds with "Hello World" on the homepage
app.get('/', function (req, res) {
    console.log("Got a GET request for the homepage");
    res.send('Hello tâm con gà nhó!!!!');
})

// This responds a POST request for the homepage
app.post('/', function (req, res) {
    console.log("Got a POST request for the homepage");
    res.send('Hello POST');
})

// This responds a DELETE request for the /del_user page.
app.delete('/del_user', function (req, res) {
    console.log("Got a DELETE request for /del_user");
    res.send('Hello DELETE');
})

// This responds a GET request for the /list_user page.
app.get('/list_user', function (req, res) {
    console.log("Got a GET request for /list_user");
    res.send('Page Listing');
})

// This responds a GET request for abcd, abxcd, ab123cd, and so on
app.get('/ab*cd', function(req, res) {   
    console.log("Got a GET request for /ab*cd");
    res.send('Page Pattern Match');
})

app.get('/betam', function(req, res) {
    console.log("Đã nhận được tâm con gà");
    res.send('Đây là trang web của Phan Thị Quỳnh Anh\n Mại dô mại dô bà con làng xóm đây là bà già khó tính Quỳnh Anh');
})

var server = app.listen(port, function () {
    var host = server.address().address
    var port = server.address().port
    console.log(`http://localhost:${port}`)
})