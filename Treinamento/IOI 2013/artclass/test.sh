echo '1\n'
for i in `seq 1 9`;
do
  cp images/style-1/style-1-$i.jpg artclass.jpg
  ./artclass
  rm artclass.jpg
done

echo '2\n'
for i in `seq 1 9`;
do
  cp images/style-2/style-2-$i.jpg artclass.jpg
  ./artclass
  rm artclass.jpg
done

echo '3\n'
for i in `seq 1 9`;
do
  cp images/style-3/style-3-$i.jpg artclass.jpg
  ./artclass
  rm artclass.jpg
done

echo '4\n'
for i in `seq 1 9`;
do
  cp images/style-4/style-4-$i.jpg artclass.jpg
  ./artclass
  rm artclass.jpg
done
