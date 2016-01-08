#!/bin/sh

NPARTS="1000 2000"
LOOPS=10000
LOGEXT=dat

cd $PBS_O_WORKDIR

rm -f logs/external.$LOGEXT
for particles in $NPARTS
do
    ./a.out | grep -v CPU >> external.$LOGEXT
done

# time to say 'Good bye' ;-)
#
exit 0

