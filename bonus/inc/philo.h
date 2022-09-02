/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:13:55 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/03 00:50:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sempahore.h>

# define ENGH_EAT "END of GAME : All philosophers ate enough"
# define ERR_ARG1 "ARG 1: number_of_philsophers must be a valid >0 number"
# define ERR_ARG2 "ARG 2: time_to_die (ms) must be a valid >0 number"
# define ERR_ARG3 "ARG 3: time_to_eat (ms) must be a valid >0 number"
# define ERR_ARG4 "ARG 4: time_to_sleep (ms) must be a valid >0 number"
# define ERR_ARG5 "ARG 5: nb_times_each_philo_eats must be a valid >0 number"

# define USLEEP_INC 100
# define EVENPHILO_OFFSET 10000

typedef struct s_data
{
	int				nb_philos;
	long			tm_die;
	long			tm_eat;
	long			tm_sleep;
	int				min_eats;
	long			start;
	char			*txt_status[5];
	sem_t			*forks;
	sem_t			*eat_more;
	sem_t			*common_access;
	sem_t			*death;
}	t_data;

typedef struct s_philo
{
	int				id;
	long			tm_die;
	long			tm_eat;
	long			tm_sleep;
	int				min_eats;
	t_data			*param;
	int				pid;
	int				status;
	long			last_eat;
	int				nb_eats;
	struct s_philo	*next;
}	t_philo;

enum
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};


enum
{
	NO,
	YES
};

enum
{
	LEFT,
	RIGHT
};

// main.c
int		main(int argc, char ** argv);
int		ft_case1philo(t_philo *philo);
void	*ft_philolife(void *philo);
void	ft_startthreads(t_philo *philo);
void	ft_endthreads(t_philo *philo);

// monitoring.c
int		ft_monitoring(t_philo *philo);
int		ft_checkdeath(t_philo *philo);
int		ft_checkenougheat(t_philo *philo);
int		ft_game_is_on(t_philo *philo);

// initialize.c
int		ft_init_param(t_data *param, int argc, char **argv);
t_philo	*ft_init_philo(t_data *param);
t_philo	*ft_new_philo(t_philo *philo, t_data *param, int i);

// time.c
long	ft_gettime(long start);
long	ft_us(struct timeval time);
long	ft_elapsedtime(double start, double tick);
int		ft_myusleep(t_philo *philo, long time);

// memory.c
char	*ft_mem_alloc(int n);
void	ft_bzero(void *s, size_t n);
void	ft_free_philo(t_philo *philo);

// utils.c
size_t	ft_strlen(const char *str);
size_t		ft_strlen(const char *str);
long		ft_atoi(const char *nptr);
char		*ft_itoa(long  n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// parsing.c
int	ft_parsing(int argc, char **argv);
int	ft_isvalidentry(char *src);
int	ft_argerr(void);

// actions.c
int	ft_sleep(t_philo *philo);
int	ft_think(t_philo *philo);
int	ft_changestatus(t_philo *philo, int status);

// eating.c
int ft_take2forks(t_philo *philo);
int	ft_letfork(t_philo *philo);
int	ft_update_eat_count(t_philo *philo);
int	ft_eat(t_philo *philo);

#endif
