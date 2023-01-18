/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:38:56 by jison             #+#    #+#             */
/*   Updated: 2023/01/17 16:02:29 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define STDIN	0
# define STDOUT	1
# define STDERR	2

# define TRUE 	1
# define FALSE	0

# define CMD_SA		0
# define CMD_PA		1
# define CMD_RA		2
# define CMD_RRA	3
# define CMD_SB		4
# define CMD_PB		5
# define CMD_RB		6
# define CMD_RRB	7
# define CMD_SS		8
# define CMD_RR		9
# define CMD_RRR	10

# define CYCLE_A	0
# define CYCLE_B	1

# define CMD_TYPE_S		0
# define CMD_TYPE_P		1
# define CMD_TYPE_R		2
# define CMD_TYPE_RR	3

# define ERR_MSG "Error\n"

typedef struct s_cycle_node
{
	struct s_cycle_node	*next;
	struct s_cycle_node	*prev;
	int					value;
	int					size;
}				t_cycle_node;

typedef struct s_cycle
{
	t_cycle_node	*top;
	t_cycle_node	*bottom;
	int				size;
}				t_cycle;

typedef struct s_pair
{
	t_cycle	*a;
	t_cycle	*b;
}				t_pair;

typedef struct s_range
{
	t_cycle_node	*lo;
	t_cycle_node	*hi;
	int				size;
}				t_range;

void			ft_fprint(int fd, const char *str);
void			handle_error(const char *message);

int				is_space(const char c);
int				is_digit(const char c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			**ft_split(const char *str);
long			ft_atol(const char *str, char **endptr);
void			*ft_memchr(const void *s, int c, ssize_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

t_cycle			*new_cycle(void);
t_cycle_node	*new_cycle_node(int value);
void			push(t_cycle *list, t_cycle_node *node);
t_cycle_node	*pop(t_cycle *list);
void			rotate(t_cycle *list);
void			r_rotate(t_cycle *list);
void			free_cycle(t_cycle *list);

t_cycle			*get_cycle(int ac, char **av);

int				get_cmd_id(const int cycle_id, const int cmd_type);
const char		*get_cmd_string(const int cmd_id);
void			adjust(t_cycle *pair[], const int cmd_id);
void			adjust_n(t_cycle *pair[], const int cmd_id, int cnt);

int				cmd_sa(t_cycle *pair[]);
int				cmd_pa(t_cycle *pair[]);
int				cmd_ra(t_cycle *pair[]);
int				cmd_rra(t_cycle *pair[]);
int				cmd_sb(t_cycle *pair[]);
int				cmd_pb(t_cycle *pair[]);
int				cmd_rb(t_cycle *pair[]);
int				cmd_rrb(t_cycle *pair[]);
int				cmd_ss(t_cycle *pair[]);
int				cmd_rr(t_cycle *pair[]);
int				cmd_rrr(t_cycle *pair[]);

int				inequ_chain(int a, int b, int c);
void			set_nums(int nums[], t_range range);
void			mysort_tri(int nums[], t_cycle *pair[]);
void			mysort_tri2(int nums[], t_cycle *pair[]);
void			mysort_tri_por(t_cycle *pair[]);
void			mysort_tri_por2(int nums[], t_cycle *pair[]);

void			sort(t_cycle *a);
void			mysort(t_cycle *pair[], t_range range);
void			mysort_mini(t_cycle *pair[], t_range range);
int				node_dist(t_cycle_node *lo, t_cycle_node *hi);
t_range			node_range(t_cycle_node *lo, t_cycle_node *hi);
int				get_pivot(t_cycle *cycle, int cnt);
int				is_sorted(t_range range);
void			range_to_top(t_cycle *pair[], t_range range);
void			quick_sort(int arr[], int left, int right);

#endif
