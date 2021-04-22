my @character = ("A".."Z", "a".."z");
my @len = (1..3);

#declare an array
my @array;
#define the starting time
my $start = time;
#generate radom names and ages
for($i = 0; $i <50; $i = $i + 1){
    my $name;
    my $age;
    for(@len){
        $name = $name.$character[rand @character];
    }
    $age=int(rand(100));
    #flag to check duplicate name
    $flg=0;
    for($j=0;$j<$i;$j++){
        if($array[$j][0]==$name){
            $flg=1;
            break;
        }
    }
    if($flg==0){
        $array[$i][0] = $name;
        $array[$i][1] = $age;
    }else{
        $i=$i-1;
    }
}
#calculate total execution time
my $duration = time - $start;
print "Time for using array is $duration s\n";