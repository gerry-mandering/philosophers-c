#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*t_function(void *data)
{
	int	num = *((int *)data);
	printf("num %d\n", num);
	sleep(1);
	return ((void *)(num * num));
}

int	main()
{
	pthread_t	p_thread;
	int			ret;
	int			status;
	int			a = 100;

	ret = pthread_create(&p_thread, NULL, t_function, (void *)&a);
	if (ret < 0)
	{
		perror("thread create error");
		exit(EXIT_FAILURE);
	}

	pthread_join(p_thread, (void *)&status);
	printf("thread join : %d\n", status);
	return (0);
}