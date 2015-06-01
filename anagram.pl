#!  /usr/bin/perl
my @ana ;
$i= $ARGV[0] ;
#print " FInding anagram for $i \n" ;
$counter = 0 ; # always points to the next index ;
sub anagram {
	my $input = $_[0] ; 
	
    #print " Input is $input \n" ;
	if ( length($input) == 2 ) {
		$ana[0] = $input ;
		@tmp = split ( //, $input );
		$ana[1] = $tmp[1].$tmp[0];
		$counter = 2 ;	
		# print ( "ana is -- @ana --\n" );
	} else {
		$rem = substr ( $input, 1  ) ;
		my $curr_char = substr ( $input, 0,1 );
	    # print " ### Input is $input ; Remainder is $rem " ; 
		# print " -- Current char is $curr_char #####\n" ;
		anagram ( $rem ) ;
		# print "Input is $input \n" ; 
		@tmp = ();
		foreach $a ( @ana ) {
			$len = length($a);
			for ( $i=0; $i <=  $len ; $i++ ){
				# put $a in that position.
				if ( $i == 0 ) {
					$n = $curr_char.$a ;
				} elsif ( $i == $len )  {
					$n = $a.$curr_char ;
				} else {	
					$end = substr ( $a, $i ) ;
					$start = substr ( $a, 0, $i );
					$n = $start.$curr_char.$end ;
				}
				# print "i = $i ; new =$n \n";
				push @tmp, $n ;
			}

		}
		@ana = @tmp ;
	}
	
}
anagram ( $i ) ; 
foreach $ag (  @ana ) {
	print "$ag\n" ; 

} 
