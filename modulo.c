#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0)
#define HAVE_PROC_OPS
#endif

#define PROC_NAME "K_RODRIGO_DEV"

// Função para inicializar a sequência
static void *my_seq_start(struct seq_file *s, loff_t *pos)
{
    static unsigned long counter = 0;

    if (*pos == 0) {
        return &counter;
    }

    *pos = 0;
    return NULL;
}

// Função para avançar para o próximo item da sequência
static void *my_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
    unsigned long *tmp_v = (unsigned long *)v;
    (*tmp_v)++;
    (*pos)++;
    return NULL;
}

// Função para finalizar a sequência
static void my_seq_stop(struct seq_file *s, void *v)
{
}

// Função para exibir um item da sequência
static int proc_show(struct seq_file *s, void *v)
{
    loff_t *spos = (loff_t *)v;
    int episode_number = (int)(*spos);
    const char *episode_name;

    switch (episode_number)
    {
        case 0:
            episode_name = "Episódio I: A Ameaça Fantasma";
            break;
        case 1:
            episode_name = "Episódio II: Ataque dos Clones";
            break;
        case 2:
            episode_name = "Episódio III: A Vingança dos Sith";
            break;
        case 3:
            episode_name = "Episódio IV: Uma Nova Esperança";
            break;
        case 4:
            episode_name = "Episódio V: O Império Contra-Ataca";
            break;
        case 5:
            episode_name = "Episódio VI: O Retorno de Jedi";
            break;
        case 6:
            episode_name = "Episódio VII: O Despertar da Força";
            break;
        case 7:
            episode_name = "Episódio VIII: Os Últimos Jedi";
            break;
        case 8:
            episode_name = "Episódio IX: A Ascensão Skywalker";
            break;
        default:
            episode_name = "Episódio Desconhecido";
            break;
    }

    seq_printf(s, "%s\n", episode_name);
    return 0;
}

static struct seq_operations my_seq_ops = {
    .start = my_seq_start,
    .next = my_seq_next,
    .stop = my_seq_stop,
    .show = proc_show,
};

// Função chamada ao abrir o arquivo /proc
static int my_open(struct inode *inode, struct file *file)
{
    return seq_open(file, &my_seq_ops);
}

#ifdef HAVE_PROC_OPS

static const struct proc_ops proc_fops = {
    .proc_open = my_open,
    .proc_read = seq_read,
    .proc_lseek = seq_lseek,
    .proc_release = seq_release,
};

#else

static const struct file_operations proc_fops = {
    .open = my_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = seq_release,
};

#endif

// Função de inicialização do módulo
static int __init porc_init(void)
{
    struct proc_dir_entry *entry;
    entry = proc_create(PROC_NAME, 0, NULL, &proc_fops);

    if (entry == NULL) {
        remove_proc_entry(PROC_NAME, NULL);
        pr_debug("Erro: Não foi possível inicializar /proc/%s\n", PROC_NAME);
        return -ENOMEM;
    }

    pr_debug("Processo %s adicionado com sucesso!\n", PROC_NAME);
    return 0;
}

// Função de saída do módulo
static void __exit proc_exit(void)
{
    remove_proc_entry(PROC_NAME, NULL);
    pr_debug("/proc/%s removido\n", PROC_NAME);
    pr_debug("Que a Força esteja com você, jovem programador!\n");
}

module_init(porc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KAUÃ RODRIGO DE LIMA BARBOSA");
MODULE_DESCRIPTION("Módulo do kernel Linux com tema Star Wars");
