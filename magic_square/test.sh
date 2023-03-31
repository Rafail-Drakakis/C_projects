#!/bin/sh
# Check if there are two arguments
if [ $# -eq 2 ]; then
   if ! [ -d "$2" ]; then
     /bin/echo "$2 is not a directory."
     exit 1
   fi
else
   /bin/echo "Usage: $0 <executable> <folder with tests>"
   exit 1
fi

# who am I?
LOGIN=`whoami`

/bin/echo "Testing -check flag"

# create a temporary directory to store the results
mkdir -p /tmp/${LOGIN}/
for i in `ls $2/check/*.in`; do
    f=$(basename $i)
    # remove previous results
    rm -f /tmp/${LOGIN}/${f%in}out;
    # run the executable to produce the result
    ./$1 -check < $i > /tmp/${LOGIN}/${f%in}out;
    # Diff ignoring empty lines (-B)
    diff -B ${i%in}out /tmp/${LOGIN}/${f%in}out;
    ans=$?
    # Print the test filename
    /bin/echo -n $i' :';
    # Check if there where any diffs or not
    if [ $ans -eq 0 ]; then
        /bin/echo -e '\e[30G \e[32;1mPASS\e[0m';
    else
        /bin/echo -e '\e[30G \e[31;1mFAIL\e[0m';
    fi
done


/bin/echo ""
/bin/echo "Testing -create flag"

for i in 1 3 5 7 13 77 99
do
    ./$1 -create $i > /tmp/${LOGIN}/gen${i}.out;

    diff -B tests/create/gen${i}.out /tmp/${LOGIN}/gen${i}.out;
    ans=$?
    # Print the test filename
    /bin/echo -n create $i' :';
    # Check if there where any diffs or not
    if [ $ans -eq 0 ]; then
        /bin/echo -e '\e[30G \e[32;1mPASS\e[0m';
    else
        /bin/echo -e '\e[30G \e[31;1mFAIL\e[0m';
    fi

done
