const express = require('express')
const app = express()
var port = 3000

// This responds with "Hello World" on the homepage
app.get('/', function (req, res) {
    console.log("Got a GET request for the homepage");
    // response.writeHead(302, {
    //     'Location': 'download'
    // });
    // response.end();// res.send('Hello tâm con gà nhó!!!!');
})

app.get('/download', function(req, res){
    const file = `${__dirname}/file/WC08_telephone.pdf`;
    res.download(file); // Set disposition and send it.
});

var server = app.listen(port, function () {
    var host = server.address().address
    var port = server.address().port
    console.log(`http://localhost:${port}`)
})