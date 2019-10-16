/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 13:03:47 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/23 10:55:31 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct		s_hash
{
	char			*name;
	int				index;
	struct s_hash	*next;
}					t_hash;

typedef struct		s_links
{
	int				index;
	char			*str;
	char			bfs_visited;
	char			trav_visited;
	int				distance;
	int				num_links;
	char			in;
	char			out;
	struct s_links	*next;
}					t_links;

typedef struct		s_queue
{
	t_links			**nodes;
	int				index;
	int				size;
}					t_q;

typedef struct		s_path
{
	int				size;
	t_links			*node;
	struct s_path	*next;
}					t_path;

typedef struct		s_store
{
	char			*str;
	struct s_store	*next;
}					t_store;

typedef struct		s_ants
{
	char			done;
	int				path_index;
	int				index;
}					t_ants;

typedef struct		s_rp
{
	char			**str;
	int				size;
	int				temp_size;
}					t_rp;

typedef struct		s_table
{
	int				num_real_paths;
	int				num_of_paths;
	int				ants;
	int				rooms;
	char			*start;
	char			*end;
	int				start_index;
	int				end_index;
	struct s_hash	**hash_table;
	struct s_links	**link_table;
	struct s_path	**temp_paths;
	struct s_path	**paths;
	struct s_rp		**rp;
	struct s_ants	**ant_table;
	struct s_store	*storage;
}					t_table;

void				store_input(t_table *lem);

int					input_type(char *str);

void				print_storage(t_table *lem);

void				wrong_input_error(t_table *lem, char *line);
void				no_start_end_error(t_table *lem);
void				no_connection_error(t_table *lem);
void				room_not_found_error(t_table *lem);
void				multiple_start_end_error(t_table *lem);

int					lemin_hash(char *str, int rooms);
int					link_index(t_table *lem, char *str);
t_links				*get_link(t_table *lem, char *str);
int					lemin_list_len(t_links *list);

void				make_tables(t_table *lem);

void				add_link(char *str, t_table *lem);

int					new_bfs(t_table *lem, int first_or_second);

t_q					*create_queue(t_table *lem);
t_links				*get_front(t_q *queue);
void				dequeue(t_q *queue);
void				enqueue(t_q *queue, int distance, t_links *node);
void				free_queue(t_q *q);

void				move_ants(t_table *lem);

void				make_real_paths(t_table *lem);

void				move_ants(t_table *lem);

void				path_traversal(t_table *lem);
int					get_path_size(t_path *path);

t_links				*get_next_node(t_table *lem, t_links *node);
void				set_in_out(t_links *node, t_links *next_node);
void				remove_dead_links(t_table *lem);
t_links				*get_lowest_distance(t_table *lem, t_links *node);
void				make_path(t_table *lem, t_path *path);

void				free_everything(t_table *lem);

void				free_storage(t_table *lem);
void				free_rp(t_table *lem);
void				free_link_table(t_table *lem);
void				free_hash_table(t_table *lem);

char				*get_room_name(char *str);
void				print_movement(int which_ant, char *str);
int					return_shortest_path_index(t_table *lem);
void				reset_visited(t_table *lem, int first_or_second);
int					can_backtrack(t_table *lem, t_links *node);

int					ft_fits_in_int(char *str);

#endif
