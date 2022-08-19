/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:13:55 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/19 09:22:25 by mbourgeo         ###   ########.fr       */
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
# define DET_ARG1 " 1-> number_of_philosophers"
# define DET_ARG2 " 2-> time_to_die (ms)"
# define DET_ARG3 " 3-> time_to_eat (ms)"
# define DET_ARG4 " 4-> time_to_sleep (ms)"
# define DET_ARG5 "[5-> number_of_times_each_philosopher_must_eat]"

typedef struct s_data
{
	int				nb_philos;
	int				tm_die;
	int				tm_eat;
	int				tm_sleep;
	int				nb_eats;
	char			**status;
	struct timeval	start;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	int				status;
	int				st_eat;
	int				st_sleep;
	int				st_think;
	int				st_die;
	struct s_philo	*prev;
	struct s_philo	*next;
	t_data			param;
}	t_philo;

enum
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};

// philo.c
int		ft_philo(int argc, char ** argv);
void	*ft_trytoeat(void *temp);
void	ft_roundcheck(t_data *param, t_philo *philo);

// initialize.c
int		ft_init_param(t_data *param, struct timeval start, int argc, char **argv);
t_philo	*ft_init_philo(const t_data param);
t_philo	*ft_new_philo(t_data param, t_philo *philo, int i);

// time.c
void	ft_gettime(struct timeval *tick);
//double	ft_tick_ms(struct timeval *tick);
double	ft_time_diff_ms(struct timeval *start, struct timeval *end);

// print_infos.c
//int		ft_printstate(t_philo *philo);
int		ft_msg(char *str);
void	ft_statechange(t_philo *philo, int status);

// memory.c
char	*ft_mem_alloc(int n);
void	ft_bzero(void *s, size_t n);
void	ft_free_all(t_philo **philo);

// errors.c
int	ft_msgerr(char *str);

// utils.c
size_t	ft_strlen(const char *str);
//char	*ft_strdup(const char *str);
int		ft_atoi(const char *nptr);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);

// nbrstr.c
//char	*ft_strdup(const char *s);
char	*ft_nbrstr(double f);
void	ft_putstr_fd(char *s, int fd);

#endif
