let express = require('express');
let router = express.Router();

router.get('/abc', function(req, res){
    res.send("test get ok");
});

router.post('/abc', function(req, res){
    res.send("test post ok");
});

router.get('/rg/:id[0-9]{5}', function(req, res){
    res.send('The value is: ' + req.params.id);
});

// router.use('/abc', function(req, res, next){
//     console.log('Time: ' + Date.now());
//     next();
// });

module.exports = router;