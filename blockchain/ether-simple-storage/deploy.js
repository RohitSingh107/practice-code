"use strict";
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
exports.__esModule = true;
var ethers_1 = require("ethers");
var fs = require("fs-extra");
function main() {
    return __awaiter(this, void 0, void 0, function () {
        var provider, wallet, abi, binary, contractFactory, contract, transactionReceipt, currentFavoriteNumber, transactionResponse, transactionReceipt2, updatedFavoriteNumber;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    provider = new ethers_1.ethers.providers.JsonRpcProvider("http://127.0.0.1:7545");
                    wallet = new ethers_1.ethers.Wallet("61e90184fe27bf29c3dff1c75bc9eebff22c2398e38874fa7a5a3abefaef2ea5", provider);
                    abi = fs.readFileSync("./SimpleStorage_sol_SimpleStorage.abi", "utf8");
                    binary = fs.readFileSync("./SimpleStorage_sol_SimpleStorage.bin", "utf8");
                    contractFactory = new ethers_1.ethers.ContractFactory(abi, binary, wallet);
                    console.log("Deploying, Please wait");
                    return [4 /*yield*/, contractFactory.deploy()
                        // console.log(contract)
                    ];
                case 1:
                    contract = _a.sent();
                    return [4 /*yield*/, contract.deployTransaction.wait(1)];
                case 2:
                    transactionReceipt = _a.sent();
                    console.log("here is Deployement transaction (transaction response): ");
                    console.log(contract.deployTransaction);
                    console.log("Here is transaction receipt");
                    console.log(transactionReceipt);
                    console.log("lets depliy with only transaction data!");
                    console.log("\nInteracting with contract");
                    return [4 /*yield*/, contract.retrive()];
                case 3:
                    currentFavoriteNumber = _a.sent();
                    console.log("Current favorite number is ".concat(currentFavoriteNumber.toString()));
                    return [4 /*yield*/, contract.store("7")];
                case 4:
                    transactionResponse = _a.sent();
                    return [4 /*yield*/, transactionResponse.wait(1)];
                case 5:
                    transactionReceipt2 = _a.sent();
                    return [4 /*yield*/, contract.retrive()];
                case 6:
                    updatedFavoriteNumber = _a.sent();
                    console.log("Updated favorite number is: ".concat(updatedFavoriteNumber));
                    return [2 /*return*/];
            }
        });
    });
}
main()
    .then(function () { return process.exit(0); })["catch"](function (error) {
    console.error(error);
    process.exit(1);
});
