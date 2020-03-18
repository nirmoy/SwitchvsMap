
rm data_point.csv
for ((i = 0 ; i < 1000 ; i++)); do
	./a.out > tmp; sync
	echo $i, `cat tmp| sed -n 2p|awk '{print $1}'`, `cat tmp| sed -n 3p| awk '{print $1}'` >> data_point.csv
done
