/* Manual test harness for the bonus part of ft_printf.
 * Not part of the graded Makefile. Compares ft_printf() output/return
 * against snprintf() for the same format across flags/width/precision.
 * Build & run: make -C tests
 */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int	g_fail = 0;
static int	g_total = 0;

static void	capture_start(int *saved, int *pipefd)
{
	pipe(pipefd);
	*saved = dup(1);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
}

static void	capture_end(int saved, int pipefd_read, char *buf, size_t len)
{
	int	n;

	dup2(saved, 1);
	close(saved);
	n = read(pipefd_read, buf, len - 1);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	close(pipefd_read);
}

static void	report(const char *label, const char *got, int got_ret,
		const char *want, int want_ret)
{
	g_total++;
	if (strcmp(got, want) == 0 && got_ret == want_ret)
		return ;
	g_fail++;
	printf("FAIL %s\n  got : \"%s\" (ret=%d)\n  want: \"%s\" (ret=%d)\n",
		label, got, got_ret, want, want_ret);
}

int	main(void)
{
	char	got[512];
	char	want[512];
	int		saved;
	int		pipefd[2];
	int		got_ret;
	int		want_ret;

	// %d / %i width + minus
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%5d][%-5d][%05d]", 42, 42, 42);
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%5d][%-5d][%05d]", 42, 42, 42);
	report("d width/minus/zero", got, got_ret, want, want_ret);

	// negative numbers with zero flag
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%06d][%-6d]", -42, -42);
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%06d][%-6d]", -42, -42);
	report("d negative zero/minus", got, got_ret, want, want_ret);

	// plus / space flags
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%+d][% d][%+d]", 42, 42, -42);
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%+d][% d][%+d]", 42, 42, -42);
	report("d plus/space", got, got_ret, want, want_ret);

	// precision on d/i
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%.5d][%.0d][%8.5d]", 42, 0, 42);
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%.5d][%.0d][%8.5d]", 42, 0, 42);
	report("d precision", got, got_ret, want, want_ret);

	// %u width/zero/precision
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%6u][%-6u][%06u][%.4u]", 42u, 42u, 42u, 42u);
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%6u][%-6u][%06u][%.4u]",
			42u, 42u, 42u, 42u);
	report("u width/zero/precision", got, got_ret, want, want_ret);

	// %x / %X with hash flag and width
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%#x][%#X][%#8x][%08x][%.4x]", 255, 255, 255, 42,
			42);
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%#x][%#X][%#8x][%08x][%.4x]",
			255, 255, 255, 42, 42);
	report("x hash/width/precision", got, got_ret, want, want_ret);

	// %#x with value 0 -> no prefix
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%#x][%#.0x]", 0, 0);
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%#x][%#.0x]", 0, 0);
	report("x hash zero value", got, got_ret, want, want_ret);

	// %s width/minus/precision
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%10s][%-10s][%.3s][%10.3s]", "hi", "hi",
			"hello", "hello");
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%10s][%-10s][%.3s][%10.3s]",
			"hi", "hi", "hello", "hello");
	report("s width/minus/precision", got, got_ret, want, want_ret);

	// %c width/minus
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%5c][%-5c]", 'x', 'x');
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%5c][%-5c]", 'x', 'x');
	report("c width/minus", got, got_ret, want, want_ret);

	// %s NULL with width
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%10s]", (char *)NULL);
	capture_end(saved, pipefd[0], got, sizeof(got));
	report("s null width", got, got_ret, "[    (null)]", 12);

	// combined flags: -, 0, width, precision together
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%-010.5d][%+05d]", 42, 7);
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%-010.5d][%+05d]", 42, 7);
	report("combined flags", got, got_ret, want, want_ret);

	// %p width
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%20p][%-20p]", (void *)0x1234, (void *)0x1234);
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%20p][%-20p]",
			(void *)0x1234, (void *)0x1234);
	report("p width", got, got_ret, want, want_ret);

	// %% with width (glibc ignores width on %%, but subject examples treat
	// it like a literal char - we mimic glibc: %% takes no flags effect)
	capture_start(&saved, pipefd);
	got_ret = ft_printf("[%%][%5d]", 7);
	capture_end(saved, pipefd[0], got, sizeof(got));
	want_ret = snprintf(want, sizeof(want), "[%%][%5d]", 7);
	report("percent literal", got, got_ret, want, want_ret);

	printf("\n%d/%d tests passed\n", g_total - g_fail, g_total);
	return (g_fail != 0);
}
