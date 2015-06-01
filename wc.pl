#!  /usr/bin/perl
$s = @ARGV[0] ;
@arr = @ARGV[0] ;
chomp $s ;
print "$s \n" ;
$len = length($s) ;
print "$len \n" ; 
%counts = "" ;
@arr = split // , $s ;
foreach $alpha ( @arr ) {
	if ( $alpha =~ /\s/ ){
		next ; 
	}
        if (exists ( $counts{$alpha} ) ) {
		$counts{$alpha}++ ;
	}else{
		print " Adding $alpha \n" ;
		$counts{$alpha} = 1 ; 
	} 
	#print" $alpha - $counts{$alpha}\n" ; 
} 
print "\n";
for $alpha ( keys %counts ){
	print "Count for alphabet $alpha = $counts{$alpha} \n" ; 
}
