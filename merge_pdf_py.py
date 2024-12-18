import PyPDF2

def merge_pdfs():
    print("Enter the PDF files you want to merge, one per line (type 'done' when finished):")
    pdf_files = []

    while True:
        file = input("Enter PDF file path (or 'n' to finish): ").strip()
        if file.lower() == 'n':
            break
        pdf_files.append(file)

    if not pdf_files:
        print("No PDF files provided. Exiting.")
        return

    output_file = input("Enter the name of the output PDF file (e.g., merged.pdf): ").strip()

    try:
        merger = PyPDF2.PdfMerger()
        
        for pdf in pdf_files:
            print(f"Adding {pdf}...")
            merger.append(pdf)

        merger.write(output_file)
        merger.close()
        print(f"Merged PDF saved as {output_file}")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    merge_pdfs()