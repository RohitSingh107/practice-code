var stocks = {
    Fruits: ["stawberry", "grapes", "banana", "apple"],
    Liquid: ["water", "ice"],
    Holder: ["cone", "cup", "stick"],
    Toppings: ["chocolates", "peanuts"]
};
var is_shop_open = true;
var order = function (time, work) {
    return new Promise(function (resolve, reject) {
        if (is_shop_open) {
            setTimeout(function () {
                resolve(work());
            }, time);
        }
        else {
            reject(console.log("Our shop is closed"));
        }
    });
};
order(2000, function () { return console.log("".concat(stocks.Fruits[0], " was selected")); })
    .then(function () {
    return order(0, function () { return console.log("Prodcution has started"); });
})
    .then(function () {
    return order(0, function () { return console.log("The fruit was chopped"); });
})
    .then(function () {
    return order(1000, function () {
        console.log("".concat(stocks.Liquid[0], " and ").concat(stocks.Liquid[1], " was selected"));
    });
})
    .then(function () {
    return order(1000, function () { return console.log("start the machine"); });
})
    .then(function () {
    return order(2000, function () { return console.log("Icecream placed on ".concat(stocks.Holder[0])); });
})
    .then(function () {
    return order(3000, function () { return console.log("".concat(stocks.Toppings[0], " was selected")); });
})
    .then(function () {
    return order(1000, function () { return console.log("Icecream was served"); });
})["catch"](function () {
    console.log("Custome left");
})["finally"](function () {
    console.log("Day ended, shop is closed");
});
