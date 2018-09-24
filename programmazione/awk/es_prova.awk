#!/usr/bin/awk -f
BEGIN {
	while(getline < ARGV[2]){
		vett_cancellazioni[$0] = 1
	}
	ARGV[2] = ""
}

{
	
}


END {
	
}