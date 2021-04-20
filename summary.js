var socket = io.connect("http://"+document.domain+":"+location.port);

var contestants = []
var len
const scrwidth = document.body.clientWidth * 0.95 - 210
var curmatch=location.hash.replace(/^#/,"");
function b64EncodeUnicode(str) {
  return btoa(encodeURIComponent(str).replace(/%([0-9A-F]{2})/g,
    function toSolidBytes(match, p1) {
      return String.fromCharCode('0x' + p1);
  }));
}

function b64DecodeUnicode(str) {
  return decodeURIComponent(Array.prototype.map.call(atob(str), function(c) {
    return '%' + ('00' + c.charCodeAt(0).toString(16)).slice(-2)
  }).join(''))
}

var sfx = new Audio()
sfx.type = 'audio/wav'

const playsfx = id => {
	if(id == 'summary'){
		sfx.src = '/static/audio/Tổng_kết.wav'
	}
	sfx.play()
}

const wait = time => new Promise(resolve => setTimeout(resolve, time))

const toScore = async (scr, id) => {
	console.log(scr + " " + id + " " + len)
	console.log((scr / len * scrwidth) + 'px')
	// console.log('#scrslide' + parseInt(id + 1))
	$('#scrslide' + parseInt(parseInt(id) + 1)).animate({width:(scr / len * scrwidth) + 'px'},2000)
	for(var i = 0; i <= scr; i++){
		$('#score' + parseInt(parseInt(id) + 1)).html(i);
		await wait(2000 / scr)
	}
}

const summary = async function () {
	await new Promise(resolve => _fetch('/apix/read_file',{file : `static/data/${curmatch}_contestants.txt`}).then((res) => {
		console.log(res)
		res = b64DecodeUnicode(res)
		contestants = JSON.parse(res)
		resolve()
	}))
	console.log(contestants)
	await new Promise (resolve => {
		contestants.sort((a, b) => {return b.score - a.score})
		resolve()
	})
	len = contestants[0].score
	playsfx('summary')
	for(var i = 3; i >= 0; i--){
		$('#name' + parseInt(parseInt(i) + 1)).html(contestants[i].name)
		toScore(contestants[i].score,i)
		await wait(3500)
	}
}

const erase = () => {
	for(var i = 1; i <= 4; i++){
		$('#name' + i).html('');
		$('#score' + i).html('');
		document.getElementById('scrslide' + i).style.width = '0px'
	}
}

const end = async () => {
	await (async () => {
		res = await _fetch('/apix/read_file',{file : `static/data/${curmatch}_contestants.txt`})
		console.log(res)
		contestants = await JSON.parse(b64DecodeUnicode(res));
		console.log(contestants)
		len = 0
		for(id in contestants) len = Math.max(len, contestants[id].score)
		playsfx('summary');
		for(id in contestants){
			console.log(contestants[id])
			$('#name' + parseInt(parseInt(id) + 1)).html(contestants[id].name)
			toScore(contestants[id].score,id)
			await wait(3500)
		}
	})()
}
