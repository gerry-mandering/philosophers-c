#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*t_function(void *data)
{
	int	id;
	int	i = 0;
	id = *((int *)data);

	while (1)
	{
		printf("%d : %d\n", id, i);
		i++;
		sleep(1);
	}
}

int	main()
{
	pthread_t	p_thread[2];
	int			ret;
	int			status;
	int			a = 1;
	int			b = 2;

	ret = pthread_create(&p_thread[0], NULL, t_function, (void *)&a);
	if (ret < 0)
	{
		perror("thread create error");
		exit(EXIT_FAILURE);
	}

	ret = pthread_create(&p_thread[1], NULL, t_function, (void *)&b);
	if (ret < 0)
	{
		perror("thread create error");
		exit(EXIT_FAILURE);
	}

	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);
	return (0);
}
