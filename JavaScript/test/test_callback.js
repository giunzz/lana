function asyncFunction(callback) {
    console.log("Start");
    // setTimeout(() => {
        console.log("133");
        callback(2, 3);
    // }, 1000);
    console.log("Waiting");
    console.log("abc")
}

let printEnd = function(a, b) {
    console.log(a + b);
}

// a = 0;

function getData(link, callback) {
    // setTimeout(() => {
    //     console.log(link);
    //     callback();
    //     // console.log(link);
    //     // a = a + 1
    // }, 1000)
    callback();
    console.log(link);
}

getData("Data1", () => {
    getData("Data2", () => {
        getData("Data2", () => {
            getData("Data3", () => {
                getData("Data4", () => {
                getData("Data5", () => {
                    getData("Data6", () => {
                        console.log("Done");                     
                    })
                })
                })
            })
        })
    })
})

// asyncFunction(printEnd)
// console.log("abg");
// setTimeout(printEnd, 2000, 100, 200);
// console.log("gba");