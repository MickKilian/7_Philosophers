for i in {1..50}
do
	./philo 5 800 200 200 | grep eating | wc -l
done
