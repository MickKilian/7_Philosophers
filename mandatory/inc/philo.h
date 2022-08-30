/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:13:55 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/30 01:45:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ERR_ARGS "Please specify exactly 4 [or 5] arguments"
# define DEF_ARG1 " 1-> number_of_philosophers"
# define DEF_ARG2 " 2-> time_to_die (ms)"
# define DEF_ARG3 " 3-> time_to_eat (ms)"
# define DEF_ARG4 " 4-> time_to_sleep (ms)"
# define DEF_ARG5 "[5-> number_of_times_each_philosopher_must_eat]"
# define ENGH_EAT "END of GAME : All philosophers ate enough"
# define PHI_DEAD "END of GAME : One philosopher starved to death"
# define ERR_ARG1 "ARG 1: number_of_philsophers has to be 1 or more"
# define ERR_ARG2 "ARG 2: time_to_die (ms) has to be a positive value"
# define ERR_ARG3 "ARG 3: time_to_eat (ms) has to be a positive value"
# define ERR_ARG4 "ARG 4: time_to_sleep (ms) has to be a positive value"
# define ERR_ARG5 "ARG 5: number_of_times_each_philosopher_must_eat has to be 1 or more"

# define USLEEP_INC 10
# define EVENPHILO_OFFSET 10000

typedef struct s_fork
{
//	int				user;
//	int				used;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_data
{
	int				nb_philos;
	long long		tm_die;
	long long		tm_eat;
	long long		tm_sleep;
	long long		tempo;
	int				dead;
	pthread_mutex_t	dead_ex;
	int				enough_eat;
	pthread_mutex_t	enough_eat_ex;
	int				min_eats;
	t_fork			*fork;
	int				(*ft_action[4])();
	pthread_mutex_t	wr_mutex;
	long long		start;
	char			*txt_status[5];
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	//pthread_mutex_t	mutex;
	int				status;
	pthread_mutex_t	status_ex;
	//int				fork_side;
	t_data			*param;
	long long		last_eat;
	pthread_mutex_t	last_eat_ex;
	int				nb_eats;
	pthread_mutex_t	nb_eats_ex;
	//struct s_philo	*prev;
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

// philo.c
int		ft_philo(int argc, char ** argv);
void	*ft_philolife(void *philo);
void	ft_startthreads(t_philo *philo);
void	ft_endthreads(t_philo *philo);
int		ft_monitoring(t_philo *philo);
int		ft_checkdead(t_philo *philo);
int		ft_checkenougheat(t_philo *philo);

// initialize.c
int		ft_init_param(t_data *param, int argc, char **argv);
t_philo	*ft_init_philo(t_data *param);
t_philo	*ft_new_philo(t_philo *philo, t_data *param, int i);

// time.c
long long	ft_gettime(long long start);
//struct timeval	ft_time_diff(struct timeval *start, struct timeval *end);
long long	ft_us(struct timeval time);
long long	ft_elapsedtime(double start, double tick);
long long	ft_partms(long long time);
long long	ft_partus(long long time);
int			ft_myusleep(t_philo *philo, long long time);

// display.c
int		ft_msg(char *str);
int		ft_msgerr(char *str);
void	ft_displaystate(t_philo *philo, long long time);
void	ft_printtimems(long long time);

// memory.c
char	*ft_mem_alloc(int n);
void	ft_bzero(void *s, size_t n);
void	ft_free_philo(t_philo *philo);

// utils.c
size_t		ft_strlen(const char *str);
//char	*ft_strdup(const char *str);
long long	ft_atoi(const char *nptr);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s);
void		ft_putstr(char *s);
void		ft_putnbr(long long n);
void		ft_putnbrn(long long n, int len);

// nbrstr.c
//char	*ft_strdup(const char *s);
char	*ft_nbrstr(double f);
void	ft_putstr_fd(char *s, int fd);

// parsing.c
int	ft_parsing(int argc, char **argv);

// actions.c
int	ft_action(t_philo *philo, int action);
int ft_take2forks(t_philo *philo);
int	ft_takefork(t_philo *philo);
int	ft_letfork(t_philo *philo);
int	ft_eat(t_philo *philo);
int	ft_sleep(t_philo *philo);
int	ft_think(t_philo *philo);
int	ft_die(t_philo *philo);
int	ft_changestate(t_philo *philo, int status);

// mutex.c
int	ft_dead_ex(t_philo *philo);
int	ft_dead_ex_ch(t_philo *philo, int val);
int	ft_enough_eat_ex(t_philo *philo);
int	ft_enough_eat_ex_ch(t_philo *philo, int val);
int	ft_nb_eats_ex(t_philo *philo);
int	ft_nb_eats_ex_ch(t_philo *philo, int val);
int	ft_last_eat_ex(t_philo *philo);
int	ft_last_eat_ex_ch(t_philo *philo, int val);
int	ft_status_ex(t_philo *philo);
int	ft_status_ex_ch(t_philo *philo, int val);

#endif
