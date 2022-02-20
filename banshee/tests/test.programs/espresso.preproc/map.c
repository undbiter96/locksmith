typedef int size_t;
extern	struct	_iobuf {
int	_cnt;
unsigned char *_ptr;
unsigned char *_base;
int	_bufsiz;
short	_flag;
char	_file;	} _iob[];
typedef struct _iobuf FILE;
extern struct _iobuf	*fopen(const char *, const char *);
extern struct _iobuf	*fdopen(int, const char *);
extern struct _iobuf	*freopen(const char *, const char *, FILE *);
extern struct _iobuf	*popen(const char *, const char *);
extern struct _iobuf	*tmpfile(void);
extern long	ftell(FILE *);
extern char	*fgets(char *, int, FILE *);
extern char	*gets(char *);
extern char	*sprintf(char *, const char *, ...);
extern char	*ctermid(char *);
extern char	*cuserid(char *);
extern char	*tempnam(const char *, const char *);
extern char	*tmpnam(char *);
typedef struct sm_element_struct sm_element;
typedef struct sm_row_struct sm_row;
typedef struct sm_col_struct sm_col;
typedef struct sm_matrix_struct sm_matrix;
struct sm_element_struct {
int row_num;	int col_num;	sm_element *next_row;	sm_element *prev_row;	sm_element *next_col;	sm_element *prev_col;	char *user_word;	};
struct sm_row_struct {
int row_num;	int length;	int flag;	sm_element *first_col;	sm_element *last_col;	sm_row *next_row;	sm_row *prev_row;	char *user_word;	};
struct sm_col_struct {
int col_num;	int length;	int flag;	sm_element *first_row;	sm_element *last_row;	sm_col *next_col;	sm_col *prev_col;	char *user_word;	};
struct sm_matrix_struct {
sm_row **rows;	int rows_size;	sm_col **cols;	int cols_size;	sm_row *first_row;	sm_row *last_row;	int nrows;	sm_col *first_col;	sm_col *last_col;	int ncols;	char *user_word;	};
extern sm_matrix *sm_alloc(), *sm_alloc_size(), *sm_dup();
extern void sm_free(), sm_delrow(), sm_delcol(), sm_resize();
extern void sm_write(), sm_print(), sm_dump(), sm_cleanup();
extern void sm_copy_row(), sm_copy_col();
extern void sm_remove(), sm_remove_element();
extern sm_element *sm_insert(), *sm_find();
extern sm_row *sm_longest_row();
extern sm_col *sm_longest_col();
extern int sm_read(), sm_read_compressed();
extern sm_row *sm_row_alloc(), *sm_row_dup(), *sm_row_and();
extern void sm_row_free(), sm_row_remove(), sm_row_print();
extern sm_element *sm_row_insert(), *sm_row_find();
extern int sm_row_contains(), sm_row_intersects();
extern int sm_row_compare(), sm_row_hash();
extern sm_col *sm_col_alloc(), *sm_col_dup(), *sm_col_and();
extern void sm_col_free(), sm_col_remove(), sm_col_print();
extern sm_element *sm_col_insert(), *sm_col_find();
extern int sm_col_contains(), sm_col_intersects();
extern int sm_col_compare(), sm_col_hash();
extern int sm_row_dominance(), sm_col_dominance(), sm_block_partition();
extern sm_row *sm_minimum_cover();
extern	char	_ctype_[];
extern struct _iobuf *popen(const char *, const char *), *tmpfile(void);
extern int pclose(FILE *);
extern void rewind(FILE *);
extern void abort(void), free(void *), exit(int), perror(const char *);
extern char *getenv(const char *), *malloc(size_t), *realloc(void *, size_t);
extern int system(const char *);
extern double atof(const char *);
extern char *strcpy(char *, const char *), *strncpy(char *, const char *, size_t), *strcat(char *, const char *), *strncat(char *, const char *, size_t), *strerror(int);
extern char *strpbrk(const char *, const char *), *strtok(char *, const char *), *strchr(const char *, int), *strrchr(const char *, int), *strstr(const char *, const char *);
extern int strcoll(const char *, const char *), strxfrm(char *, const char *, size_t), strncmp(const char *, const char *, size_t), strlen(const char *), strspn(const char *, const char *), strcspn(const char *, const char *);
extern char *memmove(void *, const void *, size_t), *memccpy(void *, const void *, int, size_t), *memchr(const void *, int, size_t), *memcpy(void *, const void *, size_t), *memset(void *, int, size_t);
extern int memcmp(const void *, const void *, size_t), strcmp(const char *, const char *);
extern long util_cpu_time();
extern int util_getopt();
extern void util_getopt_reset();
extern char *util_path_search();
extern char *util_file_search();
extern int util_pipefork();
extern void util_print_cpu_stats();
extern char *util_print_time();
extern int util_save_image();
extern char *util_strsav();
extern char *util_tilde_expand();
extern void util_restart();
extern int util_optind;
extern char *util_optarg;

typedef unsigned int *pset;
typedef struct set_family {
int wsize; int sf_size; int capacity; int count; int active_count; pset data; struct set_family *next; } set_family_t, *pset_family;
extern int bit_count[256];

typedef struct cost_struct {
int cubes;	int in;	int out;	int mv;	int total;	int primes;	} cost_t, *pcost;
typedef struct pair_struct {
int cnt;
int *var1;
int *var2;
} pair_t, *ppair;
typedef struct symbolic_list_struct {
int variable;
int pos;
struct symbolic_list_struct *next;
} symbolic_list_t;
typedef struct symbolic_label_struct {
char *label;
struct symbolic_label_struct *next;
} symbolic_label_t;
typedef struct symbolic_struct {
symbolic_list_t *symbolic_list;	int symbolic_list_length;	symbolic_label_t *symbolic_label;	int symbolic_label_length;	struct symbolic_struct *next;
} symbolic_t;
typedef struct {
pset_family F, D, R;	char *filename; int pla_type; pset phase; ppair pair; char **label;	symbolic_t *symbolic;	symbolic_t *symbolic_output;
} PLA_t, *pPLA;

extern unsigned int debug; extern int verbose_debug; extern char *total_name[16]; extern long total_time[16]; extern int total_calls[16]; extern int echo_comments;	extern int echo_unknown_commands;	extern int force_irredundant; extern int skip_make_sparse;
extern int kiss; extern int pos; extern int print_solution; extern int recompute_onset; extern int remove_essential; extern int single_expand; extern int summary; extern int trace; extern int unwrap_onset; extern int use_random_order;	extern int use_super_gasp;	extern char *filename;	extern int debug_exact_minimization; struct pla_types_struct {
char *key;
int value;
};
struct cube_struct {
int size; int num_vars; int num_binary_vars; int *first_part; int *last_part; int *part_size; int *first_word; int *last_word; pset binary_mask; pset mv_mask; pset *var_mask; pset *temp; pset fullset; pset emptyset; unsigned int inmask; int inword; int *sparse; int num_mv_vars; int output; };
struct cdata_struct {
int *part_zeros; int *var_zeros; int *parts_active; int *is_unate; int vars_active; int vars_unate; int best; };
extern struct pla_types_struct pla_types[];
extern struct cube_struct cube, temp_cube_save;
extern struct cdata_struct cdata, temp_cdata_save;

extern int binate_split_select();
extern pset_family cubeunlist();
extern pset *cofactor();
extern pset *cube1list();
extern pset *cube2list();
extern pset *cube3list();
extern pset *scofactor();
extern void massive_count();
extern pset_family complement();
extern pset_family simplify();
extern void simp_comp();
extern int d1_rm_equal();
extern int rm2_contain();
extern int rm2_equal();
extern int rm_contain();
extern int rm_equal();
extern int rm_rev_contain();
extern pset *sf_list();
extern pset *sf_sort();
extern pset_family d1merge();
extern pset_family dist_merge();
extern pset_family sf_contain();
extern pset_family sf_dupl();
extern pset_family sf_ind_contain();
extern pset_family sf_ind_unlist();
extern pset_family sf_merge();
extern pset_family sf_rev_contain();
extern pset_family sf_union();
extern pset_family sf_unlist();
extern void cube_setup();
extern void restore_cube_struct();
extern void save_cube_struct();
extern void setdown_cube();
extern PLA_labels();
extern char *get_word();
extern int label_index();
extern int read_pla();
extern int read_symbolic();
extern pPLA new_PLA();
extern void PLA_summary();
extern void free_PLA();
extern void parse_pla();
extern void read_cube();
extern void skip_line();
extern foreach_output_function();
extern int cubelist_partition();
extern int so_both_do_espresso();
extern int so_both_do_exact();
extern int so_both_save();
extern int so_do_espresso();
extern int so_do_exact();
extern int so_save();
extern pset_family cof_output();
extern pset_family lex_sort();
extern pset_family mini_sort();
extern pset_family random_order();
extern pset_family size_sort();
extern pset_family sort_reduce();
extern pset_family uncof_output();
extern pset_family unravel();
extern pset_family unravel_range();
extern void so_both_espresso();
extern void so_espresso();
extern char *fmt_cost();
extern char *print_cost();
extern char *util_strsav();
extern void copy_cost();
extern void cover_cost();
extern void fatal();
extern void print_trace();
extern void size_stamp();
extern void totals();
extern char *fmt_cube();
extern char *fmt_expanded_cube();
extern char *pc1();
extern char *pc2();
extern char *pc3();
extern int makeup_labels();
extern kiss_output();
extern kiss_print_cube();
extern output_symbolic_constraints();
extern void cprint();
extern void debug1_print();
extern void debug_print();
extern void eqn_output();
extern void fpr_header();
extern void fprint_pla();
extern void pls_group();
extern void pls_label();
extern void pls_output();
extern void print_cube();
extern void print_expanded_cube();
extern void sf_debug_print();
extern find_equiv_outputs();
extern int check_equiv();
extern pset_family espresso();
extern int essen_cube();
extern pset_family cb_consensus();
extern pset_family cb_consensus_dist0();
extern pset_family essential();
extern pset_family minimize_exact();
extern pset_family minimize_exact_literals();
extern int feasibly_covered();
extern int most_frequent();
extern pset_family all_primes();
extern pset_family expand();
extern pset_family find_all_primes();
extern void elim_lowering();
extern void essen_parts();
extern void essen_raising();
extern void expand1();
extern void mincov();
extern void select_feasible();
extern void setup_BB_CC();
extern pset_family expand_gasp();
extern pset_family irred_gasp();
extern pset_family last_gasp();
extern pset_family super_gasp();
extern void expand1_gasp();
extern int util_getopt();
extern find_dc_inputs();
extern find_inputs();
extern form_bitvector();
extern map_dcset();
extern map_output_symbolic();
extern map_symbolic();
extern pset_family map_symbolic_cover();
extern symbolic_hack_labels();
extern int cube_is_covered();
extern int taut_special_cases();
extern int tautology();
extern pset_family irredundant();
extern void mark_irredundant();
extern void irred_split_cover();
extern sm_matrix *irred_derive_table();
extern pset minterms(pset_family T);
extern void explode(int var, int z);
extern void map(pset_family T);
extern output_phase_setup();
extern pPLA set_phase();
extern pset_family opo();
extern pset find_phase();
extern pset_family find_covers();
extern pset_family form_cover_table();
extern pset_family opo_leaf();
extern pset_family opo_recur();
extern void opoall();
extern void phase_assignment();
extern void repeated_phase_assignment();
extern generate_all_pairs();
extern int **find_pairing_cost();
extern int find_best_cost();
extern int greedy_best_cost();
extern int minimize_pair();
extern int pair_free();
extern pair_all();
extern pset_family delvar();
extern pset_family pairvar();
extern ppair pair_best_cost();
extern ppair pair_new();
extern ppair pair_save();
extern print_pair();
extern void find_optimal_pairing();
extern void set_pair();
extern void set_pair1();
extern pset_family primes_consensus();
extern int sccc_special_cases();
extern pset_family reduce();
extern pset reduce_cube();
extern pset sccc();
extern pset sccc_cube();
extern pset sccc_merge();
extern int set_andp();
extern int set_orp();
extern int setp_disjoint();
extern int setp_empty();
extern int setp_equal();
extern int setp_full();
extern int setp_implies();
extern char *pbv1();
extern char *ps1();
extern int *sf_count();
extern int *sf_count_restricted();
extern int bit_index();
extern int set_dist();
extern int set_ord();
extern void set_adjcnt();
extern pset set_and();
extern pset set_clear();
extern pset set_copy();
extern pset set_diff();
extern pset set_fill();
extern pset set_merge();
extern pset set_or();
extern pset set_xor();
extern pset sf_and();
extern pset sf_or();
extern pset_family sf_active();
extern pset_family sf_addcol();
extern pset_family sf_addset();
extern pset_family sf_append();
extern pset_family sf_bm_read();
extern pset_family sf_compress();
extern pset_family sf_copy();
extern pset_family sf_copy_col();
extern pset_family sf_delc();
extern pset_family sf_delcol();
extern pset_family sf_inactive();
extern pset_family sf_join();
extern pset_family sf_new();
extern pset_family sf_permute();
extern pset_family sf_read();
extern pset_family sf_save();
extern pset_family sf_transpose();
extern void set_write();
extern void sf_bm_print();
extern void sf_cleanup();
extern void sf_delset();
extern void sf_free();
extern void sf_print();
extern void sf_write();
extern int ccommon();
extern int cdist0();
extern int full_row();
extern int ascend();
extern int cactive();
extern int cdist();
extern int cdist01();
extern int cvolume();
extern int d1_order();
extern int d1_order_size();
extern int desc1();
extern int descend();
extern int lex_order();
extern int lex_order1();
extern pset force_lower();
extern void consensus();
extern pset_family cb1_dsharp();
extern pset_family cb_dsharp();
extern pset_family cb_recur_dsharp();
extern pset_family cb_recur_sharp();
extern pset_family cb_sharp();
extern pset_family cv_dsharp();
extern pset_family cv_intersect();
extern pset_family cv_sharp();
extern pset_family dsharp();
extern pset_family make_disjoint();
extern pset_family sharp();
pset do_sm_minimum_cover();
extern pset_family make_sparse();
extern pset_family mv_reduce();
extern qsort(void *, size_t, size_t, int (*) (const void *, const void *));
extern qst();
extern pset_family find_all_minimal_covers_petrick();
extern pset_family map_cover_to_unate();
extern pset_family map_unate_to_cover();
extern pset_family exact_minimum_cover();
extern pset_family gen_primes();
extern pset_family unate_compl();
extern pset_family unate_complement();
extern pset_family unate_intersect();
extern PLA_permute();
extern int PLA_verify();
extern int check_consistency();
extern int verify();
static pset Gcube;
static pset Gminterm;
pset minterms(pset_family T)
{
int size, var;
register pset last;
size = 1;
for(var = 0; var < cube.num_vars; var++)
size *= cube.part_size[var];
Gminterm = set_clear(((unsigned int *) malloc(sizeof(unsigned int) * ( ((size) <= 32 ? 2 : (((((size)-1) >> 5) + 1) + 1))))), size);
for( Gcube=T->data, last= Gcube+T->count*T->wsize; Gcube< last; Gcube+=T->wsize)
explode(cube.num_vars-1, 0);
return Gminterm;
}
void explode(int var, int z)
{
int i, last = cube.last_part[var];
for(i=cube.first_part[var], z *= cube.part_size[var]; i<=last; i++, z++)
if ((Gcube[((( i) >> 5) + 1)] & (1 << (( i) & (32-1)))))
if (var == 0)
(Gminterm[((( z) >> 5) + 1)] |= 1 << (( z) & (32-1)));
else
explode(var-1, z);
}
static int mapindex[16][16] = {
0, 1, 3, 2, 16, 17, 19, 18, 80, 81, 83, 82, 64, 65, 67, 66,
4, 5, 7, 6, 20, 21, 23, 22, 84, 85, 87, 86, 68, 69, 71, 70,
12, 13, 15, 14, 28, 29, 31, 30, 92, 93, 95, 94, 76, 77, 79, 78,
8, 9, 11, 10, 24, 25, 27, 26, 88, 89, 91, 90, 72, 73, 75, 74,
32, 33, 35, 34, 48, 49, 51, 50, 112,113,115,114, 96, 97, 99, 98,
36, 37, 39, 38, 52, 53, 55, 54, 116,117,119,118, 100,101,103,102,
44, 45, 47, 46, 60, 61, 63, 62, 124,125,127,126, 108,109,111,110,
40, 41, 43, 42, 56, 57, 59, 58, 120,121,123,122, 104,105,107,106,
160,161,163,162, 176,177,179,178, 240,241,243,242, 224,225,227,226,
164,165,167,166, 180,181,183,182, 244,245,247,246, 228,229,231,230,
172,173,175,174, 188,189,191,190, 252,253,255,254, 236,237,239,238,
168,169,171,170, 184,185,187,186, 248,249,251,250, 232,233,235,234,
128,129,131,130, 144,145,147,146, 208,209,211,210, 192,193,195,194,
132,133,135,134, 148,149,151,150, 212,213,215,214, 196,197,199,198,
140,141,143,142, 156,157,159,158, 220,221,223,222, 204,205,207,206,
136,137,139,138, 152,153,155,154, 216,217,219,218, 200,201,203,202
};
void map(pset_family T)
{
int j, k, l, other_input_offset, output_offset, outnum, ind;
int largest_input_ind, numout;
char c;
pset m;
int some_output;
m = minterms(T);
largest_input_ind = (1 << cube.num_binary_vars);
numout = cube.part_size[cube.num_vars-1];
for(outnum = 0; outnum < numout; outnum++) {
output_offset = outnum * largest_input_ind;
printf("\n\nOutput space # %d\n", outnum);
for(l = 0; l <= ((cube.num_binary_vars - 8) > ( 0) ? (cube.num_binary_vars - 8) : ( 0)); l++) {
other_input_offset = l * 256;
for(k = 0; k < 16; k++) {
some_output = 0;
for(j = 0; j < 16; j++) {
ind = mapindex[k][j] + other_input_offset;
if (ind < largest_input_ind) {
c = (m[((( ind+output_offset) >> 5) + 1)] & (1 << (( ind+output_offset) & (32-1)))) ? '1' : '.';
(--((&_iob[1]))->_cnt >= 0 ? (int)(*((&_iob[1]))->_ptr++ = (unsigned char)((c))) : ((((&_iob[1]))->_flag & 0200) && -((&_iob[1]))->_cnt < ((&_iob[1]))->_bufsiz ? ((*((&_iob[1]))->_ptr = (unsigned char)((c))) != '\n' ? (int)(*((&_iob[1]))->_ptr++) : _flsbuf(*(unsigned char *)((&_iob[1]))->_ptr, (&_iob[1]))) : _flsbuf((unsigned char)((c)), (&_iob[1]))));
some_output = 1;
}
if ((j+1)%4 == 0)
(--((&_iob[1]))->_cnt >= 0 ? (int)(*((&_iob[1]))->_ptr++ = (unsigned char)((' '))) : ((((&_iob[1]))->_flag & 0200) && -((&_iob[1]))->_cnt < ((&_iob[1]))->_bufsiz ? ((*((&_iob[1]))->_ptr = (unsigned char)((' '))) != '\n' ? (int)(*((&_iob[1]))->_ptr++) : _flsbuf(*(unsigned char *)((&_iob[1]))->_ptr, (&_iob[1]))) : _flsbuf((unsigned char)((' ')), (&_iob[1]))));
if ((j+1)%8 == 0)
printf("  ");
}
if (some_output)
(--((&_iob[1]))->_cnt >= 0 ? (int)(*((&_iob[1]))->_ptr++ = (unsigned char)(('\n'))) : ((((&_iob[1]))->_flag & 0200) && -((&_iob[1]))->_cnt < ((&_iob[1]))->_bufsiz ? ((*((&_iob[1]))->_ptr = (unsigned char)(('\n'))) != '\n' ? (int)(*((&_iob[1]))->_ptr++) : _flsbuf(*(unsigned char *)((&_iob[1]))->_ptr, (&_iob[1]))) : _flsbuf((unsigned char)(('\n')), (&_iob[1]))));
if ((k+1)%4 == 0) {
if (k != 15 && mapindex[k+1][0] >= largest_input_ind)
break;
(--((&_iob[1]))->_cnt >= 0 ? (int)(*((&_iob[1]))->_ptr++ = (unsigned char)(('\n'))) : ((((&_iob[1]))->_flag & 0200) && -((&_iob[1]))->_cnt < ((&_iob[1]))->_bufsiz ? ((*((&_iob[1]))->_ptr = (unsigned char)(('\n'))) != '\n' ? (int)(*((&_iob[1]))->_ptr++) : _flsbuf(*(unsigned char *)((&_iob[1]))->_ptr, (&_iob[1]))) : _flsbuf((unsigned char)(('\n')), (&_iob[1]))));
}
if ((k+1)%8 == 0)
(--((&_iob[1]))->_cnt >= 0 ? (int)(*((&_iob[1]))->_ptr++ = (unsigned char)(('\n'))) : ((((&_iob[1]))->_flag & 0200) && -((&_iob[1]))->_cnt < ((&_iob[1]))->_bufsiz ? ((*((&_iob[1]))->_ptr = (unsigned char)(('\n'))) != '\n' ? (int)(*((&_iob[1]))->_ptr++) : _flsbuf(*(unsigned char *)((&_iob[1]))->_ptr, (&_iob[1]))) : _flsbuf((unsigned char)(('\n')), (&_iob[1]))));
}
}
}
((m) ? (free((char *) (m)), (m) = 0) : 0);
}