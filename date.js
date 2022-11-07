"use strict";

var yearFirst = "1995/12/24";
var dayFirst = "29/02/2000";

console.log( parse(yearFirst) );
console.log( parse(dayFirst) );

function parse( date ) {
    var arr = date.split("/");
    var i = (arr[0].length >> 2) & 1;
    var day = arr[ i + i ];
    var year = arr[ 2 - ( i + i) ];
    var month = arr[1];

    return {
        "year" : parseInt(year),
        "month" : parseInt(month),
        "day" : parseInt(day)
    };
}
