const express = require('express')
const app = express()
var port = 3000

app.get('/', (req, res) => res.send('Hello World!'))

app.listen(port, () => console.log(`http://localhost:${port}`))