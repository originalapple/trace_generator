#C++ file compile
filename=$1
output=$(echo "$filename" | cut -f 1 -d '.')

compile : 
	g++ -o $(output) $(filename)
