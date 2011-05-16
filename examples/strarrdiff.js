
var a    = ["bokko", "bokkko", "bokkkko"];
var b    = ["bokkko", "bokko", "cubicdaiya"];
var dtl  = require('dtl');
var diff = new dtl.Diff(a, b);

diff.compose();
console.log("editdistance:" + diff.editdistance());
console.log("lcs:" + diff.lcs());
diff.printSES();
console.log("Unified Diff:");
diff.composeUnifiedHunks();
diff.printUnifiedFormat();

