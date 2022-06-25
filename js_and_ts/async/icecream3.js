var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (_) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
var stocks = {
    Fruits: ["stawberry", "grapes", "banana", "apple"],
    Liquid: ["water", "ice"],
    Holder: ["cone", "cup", "stick"],
    Toppings: ["chocolates", "peanuts"]
};
var is_shop_open = false;
// async function order() {
// 	try{
// 		await abc;
// 	}
// 	catch(error){
// 		console.log("Runs code anyway")
// 		console.error(error)
// 	}
// 	finally{
// 		console.log("Runs code anyway");
// 	}
// }
function timef(ms) {
    return new Promise(function (resolve, reject) {
        if (is_shop_open) {
            setTimeout(resolve, ms);
        }
        else {
            reject(console.log("Shop is closed"));
        }
    });
}
function kitchen() {
    return __awaiter(this, void 0, void 0, function () {
        var error_1;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    _a.trys.push([0, 9, 10, 11]);
                    return [4 /*yield*/, timef(2000)];
                case 1:
                    _a.sent();
                    console.log("".concat(stocks.Fruits[0], " was selected"));
                    return [4 /*yield*/, timef(0)];
                case 2:
                    _a.sent();
                    console.log("Start the Production");
                    return [4 /*yield*/, timef(2000)];
                case 3:
                    _a.sent();
                    console.log("cut the fruit");
                    return [4 /*yield*/, timef(0)];
                case 4:
                    _a.sent();
                    console.log("".concat(stocks.Liquid[0], " and ").concat(stocks.Liquid[1], " was added"));
                    return [4 /*yield*/, timef(1000)];
                case 5:
                    _a.sent();
                    console.log("Start the machine");
                    return [4 /*yield*/, timef(2000)];
                case 6:
                    _a.sent();
                    console.log("Icecream placed on ".concat(stocks.Holder[0]));
                    return [4 /*yield*/, timef(3000)];
                case 7:
                    _a.sent();
                    console.log("".concat(stocks.Toppings[0], " was selected"));
                    return [4 /*yield*/, timef(2000)];
                case 8:
                    _a.sent();
                    console.log("serve the icecream");
                    return [3 /*break*/, 11];
                case 9:
                    error_1 = _a.sent();
                    console.log("Customer left", error_1);
                    return [3 /*break*/, 11];
                case 10:
                    console.log("Day ended, shop closed");
                    return [7 /*endfinally*/];
                case 11: return [2 /*return*/];
            }
        });
    });
}
kitchen();
