my @character = ("A".."Z", "a".."z");
my @len = (1..3);

#declare a hash
my %hash;
#define the starting time
my $start = time;
#generate radom names and ages
for($i = 0; $i <50; $i = $i + 1){
    my $name;
    my $age;
    for(@len){
        $name = $name.$character[rand @character];
    }
    $age=int(rand(80));
    $hash{$name} = $age;
}
#calculate total execution time
my $duration = time - $start;
# print "@{[%hash]}";
print "Time for using hash is $duration s\n";