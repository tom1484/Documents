import sys

if '' not in sys.path:
    sys.path.insert(0, '')

from utils.judge import Judge
from utils import definition

from utils.export import export
from utils import detect as dt

from tkinter.filedialog import askdirectory, askopenfilename
from tkinter import Tk
from tkinter import Frame, Entry, Button, StringVar, Label
from tkinter.ttk import Progressbar

from threading import Thread

# ==================================================================================================

# create window
window = Tk()
window.title('Sheet Reader')
window.configure(background='white')
window.lift()

# ==================================================================================================

# create root
root = Frame()
root.grid(row=0, column=0, padx=5, pady=5)

root.configure(bg='white')

# ==================================================================================================

# create label for sheet dir entry
answer_file_label = Label(root, text='答案:')
answer_file_label.grid(row=0, column=0,
                       padx=5, pady=5, sticky='e')

# create sheet dir entry
answer_file_var = StringVar()

answer_file_entry = Entry(root)
answer_file_entry.grid(row=0, column=1, columnspan=2,
                       padx=5, pady=5)

# create sheet dir select button
answer_file_select_button = Button(root, text='開啟')
answer_file_select_button.grid(row=0, column=3,
                               padx=5, pady=5)

# ==================================================================================================

# create label for sheet dir entry
sheet_dir_label = Label(root, text='圖檔:')
sheet_dir_label.grid(row=1, column=0,
                     padx=5, pady=5, sticky='e')

# create sheet dir entry
sheet_dir_var = StringVar()

sheet_dir_entry = Entry(root)
sheet_dir_entry.grid(row=1, column=1, columnspan=2,
                     padx=5, pady=5)

# create sheet dir select button
sheet_dir_select_button = Button(root, text='開啟')
sheet_dir_select_button.grid(row=1, column=3,
                             padx=5, pady=5)

# ==================================================================================================

# create label for output entry
output_label = Label(root, text='輸出:')
output_label.grid(row=2, column=0,
                  padx=5, pady=5, sticky='e')

# create output entry
output_name_var = StringVar()

output_name_entry = Entry(root)
output_name_entry.grid(row=2, column=1, columnspan=2,
                       padx=5, pady=5)

# ==================================================================================================

# create mode label
mode_label = Label(root, text='模式:')
mode_label.grid(row=3, column=0,
                padx=5, pady=5, sticky='e')

# create mode select button for junior
mode_junior_button = Button(root, text='國中')
mode_junior_button.grid(row=3, column=1,
                        padx=5, pady=5, sticky='ew')

# create mode select button for senior
mode_senior_button = Button(root, text='高中')
mode_senior_button.grid(row=3, column=2,
                        padx=5, pady=5, sticky='ew')

# ==================================================================================================

# create label for progress
progress_label = Label(root, text='進度:')
progress_label.grid(row=4, column=0,
                    padx=5, pady=5, sticky='e')

# create progress
progress_bar = Progressbar(root, orient="horizontal", mode="determinate")
progress_bar.grid(row=4, column=1, columnspan=2,
                  padx=5, pady=5, sticky='ew')

# create label for progress
processed_num = Label(root, text='')
processed_num.grid(row=4, column=3,
                   padx=5, pady=5, sticky='ew')


# ==================================================================================================

# keep updating GUI
def gui_updater():
    root.update()
    root.after(100, gui_updater)


# ==================================================================================================

# used as progress updater
def update_progress(v):
    progress_bar["value"] = v


# ==================================================================================================

# used as progress updater
def update_processed_num(v):
    processed_num.configure(text=v)


# ==================================================================================================

# run calculation
def run_result(fmt):
    # build judge and read answer
    judge = Judge(fmt["answer_format"])
    res_start, res_end = judge.read_answer(answer_file_var.get())

    # read sheet dir
    sheet_dir = sheet_dir_var.get()

    output_name = output_name_var.get()
    if ".xlsx" not in output_name:
        output_name += ".xlsx"

    results, failures = dt.read_sheets(sheet_dir,
                                       fmt, judge,
                                       lambda v: update_progress(v),
                                       lambda v: update_processed_num(v))
    export(res_start, res_end,
           results, failures,
           output_name)

    window.destroy()
    exit("Done!")


# ==================================================================================================

# choose sheet dir
def choose_answer_file():
    answer_file = askopenfilename()
    answer_file_entry.insert(0, answer_file)


# ==================================================================================================

# choose sheet dir
def choose_sheet_dir():
    sheet_dir = askdirectory()
    sheet_dir_entry.insert(0, sheet_dir)


# ==================================================================================================

# choose sheet dir
def start(mode):
    if output_name_var.get() == "" or answer_file_var.get() == "" or sheet_dir_var.get() == "":
        return

    fmt = definition.formats[mode]
    t = Thread(target=lambda: run_result(fmt), daemon=True)
    t.start()

    gui_updater()


# ==================================================================================================

# config folder label
answer_file_label.configure(font=("標楷體", 14),
                            fg='black', bg='white')

# config folder entry
answer_file_entry.configure(font=("標楷體", 14),
                            fg='black', bg='white',
                            borderwidth=2, relief="groove",
                            width=50,
                            textvariable=answer_file_var)

# config select button
answer_file_select_button.configure(font=("標楷體", 14),
                                    fg='black', bg='white',
                                    command=choose_answer_file)

# ==================================================================================================

# config folder label
sheet_dir_label.configure(font=("標楷體", 14),
                          fg='black', bg='white')

# config folder entry
sheet_dir_entry.configure(font=("標楷體", 14),
                          fg='black', bg='white',
                          borderwidth=2, relief="groove",
                          width=50,
                          textvariable=sheet_dir_var)

# config select button
sheet_dir_select_button.configure(font=("標楷體", 14),
                                  fg='black', bg='white',
                                  command=choose_sheet_dir)

# ==================================================================================================

# config output label
output_label.configure(font=("標楷體", 14),
                       fg='black', bg='white')

# config output entry
output_name_entry.configure(font=("標楷體", 14),
                            fg='black', bg='white',
                            borderwidth=2, relief="groove",
                            width=50,
                            textvariable=output_name_var)

# ==================================================================================================

mode_label.configure(font=("標楷體", 14),
                     fg='black', bg='white')

mode_junior_button.configure(font=("標楷體", 14),
                             fg='black', bg='white',
                             command=lambda: start("junior"))

mode_senior_button.configure(font=("標楷體", 14),
                             fg='black', bg='white',
                             command=lambda: start("senior"))

# ==================================================================================================

# config progress label
progress_label.configure(font=("標楷體", 14),
                         fg='black', bg='white')

# config processed number
processed_num.configure(font=("標楷體", 14),
                        fg='black', bg='white')

# ==================================================================================================

# show window
window.mainloop()
