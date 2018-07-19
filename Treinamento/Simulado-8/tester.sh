for i in `seq 1 30`;
do
  echo $i > $i$i
  ./2 < $i$i > $i.in
  ./1 < $i.in > $i.sol
  ./3 < $i.in > $i.out
  diff $i.out $i.sol > $i.rep
done
