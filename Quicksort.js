function swap(a, i, j) {
	var temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// shuffle function
function shuffle(array) {
	var N = array.length;
	for (var i = 0; i < N; i++) {
		var r = Math.floor(Math.random() * i);
		swap(array, i, r);
	}
}

function partition(a, lo, hi) {
	var i = lo, j = hi + 1;
	while (true) {
		while (a[++i] < a[lo])
			if (i === hi) break;
		while (a[--j] > a[lo])
			if (j === lo) break;
		if (i >= j) break;
		swap(a, i, j);
	}
	swap(a, lo, j);
	return j;
}

function sort(a, lo, hi) {
	if (hi <= lo) return;
	var j = partition(a, lo, hi);
	sort(a, lo, j - 1);
	sort(a, j + 1, hi);
}

function qsort(a) {
    shuffle(a);
	sort(a, 0, a.length - 1);
}

// array and invocation of qs
var a = [1,2,3,4,5];
qsort(a);
console.log(a);