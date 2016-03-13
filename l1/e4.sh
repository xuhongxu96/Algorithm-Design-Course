g++ -oe4 e4.cpp
echo "================="
echo "=               ="
echo "=    Exp. 4     ="
echo "=               ="
echo "=  time         ="
echo "=  complexity   ="
echo "=               ="
echo "================="
echo "================="
echo ""
echo "Heap Sort (nlogn) 1000 numbers"
time ./e4 0 1000
echo "---"
echo "Insertion Sort (n^2) 1000 numbers"
time ./e4 1 1000
echo "---"
echo "STL Sort (nlogn) 50000 numbers"
time ./e4 2 1000
echo "==="
echo ""
echo "==="
echo "Heap Sort (nlogn) 100 numbers"
time ./e4 0 100
echo "---"
echo "Insertion Sort (n^2) 100 numbers"
time ./e4 1 100
echo "---"
echo "STL Sort (nlogn) 50000 numbers"
time ./e4 2 100
echo "==="
echo ""
echo "==="
echo "Heap Sort (nlogn) 50000 numbers"
time ./e4 0 50000
echo "---"
echo "STL Sort (nlogn) 50000 numbers"
time ./e4 2 50000
echo "---"
echo "Insertion Sort (n^2) 50000 numbers"
time ./e4 1 50000
echo "==="
echo ""
echo "==="
echo "Heap Sort (nlogn) 100000 numbers"
time ./e4 0 100000
echo "---"
echo "STL Sort (nlogn) 100000 numbers"
time ./e4 2 100000
echo "==="
echo ""
echo "==="
echo "Heap Sort (nlogn) 5000000 numbers"
time ./e4 0 5000000
echo "---"
echo "STL Sort (nlogn) 5000000 numbers"
time ./e4 2 5000000
rm ./e4
