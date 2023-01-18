#include <stdio.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void	*p_function(void *data)
{
	pid_t		pid;
	pthread_t	tid;

	pid = getpid();
	tid = pthread_self();

	char	*thread_name = (char *)data;
	
	for (int i = 0; i < 3; i++)
	{
		printf("thread name : %s, tid : %x,\tpid : %u\n", thread_name, (unsigned int)tid, (unsigned int)pid);
		sleep(1);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	pthread[2];
	int			ret;
	int			status;
	char p1[] = "thread_1";
	char p2[] = "thread_2";
	char p3[] = "thread_3";

	sleep(1);

	ret = pthread_create(&pthread[0], NULL, p_function, (void *)p1);
	if (ret < 0)
	{
		perror("pthread0 create error");
		exit(EXIT_FAILURE);
	}

	ret = pthread_create(&pthread[1], NULL, p_function, (void *)p2);
	if (ret < 0)
	{
		perror("pthread1 create error");
		exit(EXIT_FAILURE);
	}

	p_function((void *)p3);

	pthread_join(pthread[0], (void**)&status);
	pthread_join(pthread[1], (void**)&status);

	printf("__END__\n");
	return (0);
}
