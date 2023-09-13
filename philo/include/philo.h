/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:03:52 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/12 15:54:58 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ----------- External library ----------- */
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

/* ----------- Colors code ----------- */
# define RESET "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

/* ----------- Exit code ----------- */
# define SUCCESS 0
# define ERROR 1

/* ----------- STRUCTURES ----------- */
/* ----------- Main structure ----------- */
struct s_god;


/* ----------- philo structure ----------- */
typedef struct 	s_philo
{
	int				philo_id;
	int				r_fork_id;
	int				l_fork_id;
	int				x_eat;
	long long		last_time_eat;
	pthread_t		thread_id;
	struct s_god	*god;
}	t_philo;

typedef struct	s_god
{
	int				nb_philo;
	int				time_death;
	int				time_sleep;
	int				time_eat;
	int				x_meal;
	int				dead;
	int				all_philo_eaten;
	long long 		start_proc;
	pthread_mutex_t	fork[250];
	pthread_mutex_t	check_meal;
	pthread_mutex_t	write;
	t_philo			philo[250];
} t_god;

/* ----------- FUNCTIONS ----------- */
int			start_threads(t_god *info);

void		*routine(void *philosophers);

/* ----------- Actions ----------- */
void		eat_philo(t_philo *philo);
void		sleep_philo(long long time_to_sleep, t_god *info);

/* ----------- Init ----------- */
int			init(t_god *info, char **av, int ac);

/* ----------- Time ----------- */
int			ms_checker(int death, int sleep, int eat);

long long	timestamp(void);
long long	passing_time(long long past, long long present);

void		ft_usleep(long long microseconds);

/* ----------- Errors ----------- */
int			error_msg(char *(str));

/* ----------- Utils ----------- */
int			ft_atoi(char *str);
int			nbr_arg(int ac);
int			ft_strlen(char *str);

void		print_action(t_god *info, int id, char *action);

/* ----------- Test ----------- */
void		show_philo_struct(t_philo *philo);
void		print_time(t_god *info);
void		print_struct(t_philo *philo);

#endif