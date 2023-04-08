g++ -std=c++11 MainTest.cpp -o Lab

echo "Old tests:"

for i in {0..9}; do
    valgrind --leak-check=full ./Lab "OLD_Inputs/input_$i.txt" > "result_$i.txt"
done

for i in {0..9}; do
    python3 GradingScript.py "result_$i.txt" "OLD_Outputs/output_$i.txt"
    rm "result_$i.txt"
done

echo "New tests:"

for i in {0..9}; do
    valgrind --leak-check=full ./Lab "NEW_Inputs/input_$i.txt" > "result_$i.txt"
done

for i in {0..9}; do
    python3 GradingScript.py "result_$i.txt" "NEW_Outputs/output_$i.txt"
    rm "result_$i.txt"
done

rm Lab
