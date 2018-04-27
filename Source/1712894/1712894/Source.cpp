#include <stdio.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>
#include<string.h>
#pragma warning(disable:4996)
struct Sinhvien
{
	wchar_t mssv[11];
	wchar_t hoten[30];
	wchar_t email[100];
	wchar_t khoa[31];
	int nienkhoa;
	wchar_t ngaysinh[11];
	wchar_t hinh[100];
	wchar_t mota[1000];
	wchar_t sothich1[1000];
	wchar_t sothich2[1000];
};
void pointer(FILE* fp, wchar_t c)
{
	long dem = 0;
	wchar_t c1;
	fseek(fp, -1L, SEEK_CUR);
	if (fgetwc(fp) == c)
	{
		fseek(fp, -1L, SEEK_CUR);
		return;
	}
	fseek(fp, -2L, SEEK_CUR);
	if (fgetwc(fp) == c)
	{
		fseek(fp, -2L, SEEK_CUR);
		return;
	}
	fseek(fp, 1L, SEEK_CUR);
	for (int i = 0; i >= 0; i++)
	{
		c1 = fgetwc(fp);
		if (c1 == c)
		{
			fseek(fp, -dem, SEEK_CUR);
			break;
		}
		else
		{
			dem++;
			fseek(fp, -dem, SEEK_CUR);
		}
	}
}
void docfile(FILE* fp, Sinhvien &a, int& sosothich)
{
	wchar_t mang1[1000];
	wchar_t mang2[1000];
	wchar_t c;
	int temp1 = 0;
	int temp2 = 0;
	sosothich = 0;
	fgetwc(fp);
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.mssv);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		pointer(fp, c);
		fwscanf(fp, L"%[^,],", &a.mssv);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.hoten);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		pointer(fp, c);
		fwscanf(fp, L"%[^,],", &a.hoten);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.email);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		pointer(fp, c);
		fwscanf(fp, L"%[^,],", &a.email);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.khoa);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		pointer(fp, c);
		fwscanf(fp, L"%[^,],", &a.khoa);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%d", &a.nienkhoa);
		fseek(fp, 2L, SEEK_CUR);
	}
	else
	{
		pointer(fp, c);
		fwscanf(fp, L"%d", &a.nienkhoa);
		fseek(fp, 1L, SEEK_CUR);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.ngaysinh);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		pointer(fp, c);
		fwscanf(fp, L"%[^,],", &a.ngaysinh);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.hinh);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		pointer(fp, c);
		fwscanf(fp, L"%[^,],", &a.hinh);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.mota);
		if (fgetwc(fp) == 44)
		{
			sosothich++;
		}
	}
	else
	{
		pointer(fp, c);
		for (int i = 0; i >= 0; i++)
		{
			mang1[i] = fgetwc(fp);
			if (mang1[i] == 44 || mang1[i] == 10)
			{
				if (mang1[i] == 44)
				{
					mang1[i] = '\0';
					sosothich++;
					break;
				}
				if (mang1[i] == 10)
				{
					mang1[i] = '\0';
					break;
				}
			}
			temp1++;
		}
		for (int i = 0; i <= temp1; i++)
		{
			a.mota[i] = mang1[i];
		}
	}

	if (sosothich == 0)
	{
		fseek(fp, -1L, SEEK_CUR);
		return;
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.sothich1);
		if (fgetwc(fp) == 44)
		{
			sosothich++;
		}
	}
	else
	{
		pointer(fp, c);
		for (int i = 0; i >= 0; i++)
		{
			mang2[i] = fgetwc(fp);
			if (mang2[i] == 44 || mang2[i] == 10)
			{
				if (mang2[i] == 44)
				{
					mang2[i] = '\0';
					sosothich++;
					break;
				}
				if (mang2[i] == 10)
				{
					mang2[i] = '\0';
					break;
				}
			}
			temp2++;
		}
		for (int i = 0; i <= temp2; i++)
		{
			a.sothich1[i] = mang2[i];
		}
	}
	if (sosothich == 1)
	{
		fseek(fp, -1L, SEEK_CUR);
		return;
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.sothich2);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		pointer(fp, c);
		fwscanf(fp, L"%[^\n]", &a.sothich2);
	}
}
void xuatfile(Sinhvien* a, int i, int* sothich)
{
	wchar_t b[50];
	wchar_t c[] = L".htm";
	wcscpy(b, a[i].mssv);
	wcscat(b, c);
	FILE* x = _wfopen(b, L"w, ccs= UTF-8");
	if (x != NULL)
	{
		fwprintf(x, L"<!DOCTYPE html PUBLIC \" -//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(x, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(x, L"	<head>\n");
		fwprintf(x, L"		<meta http-equiv=\"Content - Type\" content=\"text/html; charset = utf - 8\" />\n");
		fwprintf(x, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
		fwprintf(x, L"		<title>HCMUS - %ls</title>\n", a[i].hoten);
		fwprintf(x, L"	</head>\n");
		fwprintf(x, L"	<body>\n");
		fwprintf(x, L"		<div class=\"Layout_container\">\n");
		fwprintf(x, L"			<!-- Begin Layout Banner Region -->\n");
		fwprintf(x, L"			<div class=\"Layout_Banner\" >\n");
		fwprintf(x, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
		fwprintf(x, L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
		fwprintf(x, L"			</div>\n");
		fwprintf(x, L"			<!-- End Layout Banner Region -->\n");
		fwprintf(x, L"			<!-- Begin Layout MainContents Region -->\n");
		fwprintf(x, L"			<div class=\"Layout_MainContents\">\n");
		fwprintf(x, L"				<!-- Begin Below Banner Region -->\n");
		fwprintf(x, L"				<div class=\"Personal_Main_Information\">\n");
		fwprintf(x, L"					<!-- Begin Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
		fwprintf(x, L"					<div class=\"Personal_Location\">\n");
		fwprintf(x, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
		fwprintf(x, L"						<span class=\"Personal_FullName\">%ls - %s</span>\n", a[i].hoten, a[i].mssv);
		fwprintf(x, L"						<div class=\"Personal_Department\">Khoa %ls</div>\n", a[i].khoa);
		fwprintf(x, L"						<br />\n");
		fwprintf(x, L"						<div class=\"Personal_Phone\">\n");
		fwprintf(x, L"							Email: %ls\n", a[i].email);
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"						<br />\n");
		fwprintf(x, L"						<br />\n");
		fwprintf(x, L"					</div>\n");
		fwprintf(x, L"					<!-- End Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
		fwprintf(x, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
		fwprintf(x, L"						<img src=\"%s\" class=\"Personal_Hinhcanhan\" />\n", a[i].hinh);
		fwprintf(x, L"					</div>\n");
		fwprintf(x, L"				</div>\n");
		fwprintf(x, L"				<!-- End Below Banner Region -->\n");
		fwprintf(x, L"				<!-- Begin MainContents Region -->\n");
		fwprintf(x, L"				<div class=\"MainContain\">\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"					<!-- Begin Top Region -->\n");
		fwprintf(x, L"					<div class=\"MainContain_Top\">\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
		fwprintf(x, L"						<div>\n");
		fwprintf(x, L"							 <ul class=\"TextInList\">\n");
		fwprintf(x, L"								<li>Họ và tên: %ls</li>\n", a[i].hoten);
		fwprintf(x, L"								<li>MSSV: %ls</li>\n", a[i].mssv);
		fwprintf(x, L"								<li>Sinh viên khoa %ls</li>\n", a[i].khoa);
		fwprintf(x, L"								<li>Ngày sinh: %ls</li>\n", a[i].ngaysinh);
		fwprintf(x, L"								<li>Email: %ls</li>\n", a[i].email);
		fwprintf(x, L"							</ul>\n");
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"						<div class=\"InfoGroup\">Sở thích</div>\n");
		fwprintf(x, L"						<div>\n");
		fwprintf(x, L"							<ul class=\"TextInList\">\n");
		if (sothich[i] == 0)
		{
			fwprintf(x, L"								<li>Không có.\n</li>\n");
		}
		if (sothich[i] == 1)
		{
			fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich1);
		}
		else if (sothich[i] == 2)
		{

			fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich1);
			fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich2);
		}
		fwprintf(x, L"							</ul>\n");
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
		fwprintf(x, L"						<div class=\"Description\">\n");
		fwprintf(x, L"							%ls.\n", a[i].mota);
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"					</div>\n");
		fwprintf(x, L"				</div>\n");
		fwprintf(x, L"			</div>\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"			<!-- Begin Layout Footer -->\n");
		fwprintf(x, L"			<div class=\"Layout_Footer\">\n");
		fwprintf(x, L"				<div class=\"divCopyright\">\n");
		fwprintf(x, L"					<br />\n");
		fwprintf(x, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
		fwprintf(x, L"					<br />\n");
		fwprintf(x, L"					@2018</br>\n");
		fwprintf(x, L"					Đồ án giữa kỳ</br>\n");
		fwprintf(x, L"				Kỹ thuật lập trình</br>\n");
		fwprintf(x, L"				TH2018/04</br>\n");
		fwprintf(x, L"				1712894 - Đặng Thị Thúy Uyên</br>\n");
		fwprintf(x, L"				</div>\n");
		fwprintf(x, L"			</div>\n");
		fwprintf(x, L"			<!-- End Layout Footer -->\n");
		fwprintf(x, L"		</div>\n");
		fwprintf(x, L"	</body>\n");
		fwprintf(x, L"</html>\n");
		fwprintf(x, L"\n");
		wprintf(L" ->File %ls tạo thành công.\n", b, i + 1);
	}
	fclose(x);
}
int linecount(FILE* fp)
{
	int dem = 0;
	wchar_t c[1000];
	for (int i = 1; i > 0; i++)
	{
		if (fwscanf(fp, L"%[^\n]\n", c) != EOF)
		{
			dem++;
		}
		else return dem;
	}
}
void info(Sinhvien* b, int n, int* sothich)
{

	wprintf(L"*********Thông tin sinh viên %d**********\n", n);
	wprintf(L"Mã số sinh viên: %ls\n", b[n - 1].mssv);
	wprintf(L"Họ và tên: %ls\n", b[n - 1].hoten);
	wprintf(L"Sinh viên khoa: %ls\n", b[n - 1].khoa);
	wprintf(L"Khóa học: %d\n", b[n - 1].nienkhoa);
	wprintf(L"Ngày sinh: %ls\n", b[n - 1].ngaysinh);
	wprintf(L"Đường dẫn hình ảnh: %ls\n", b[n - 1].hinh);
	wprintf(L"Mô tả: %ls\n", b[n - 1].mota);
	wprintf(L"Email: %ls\n", b[n - 1].email);
	if (sothich[n - 1] == 0)
	{
		wprintf(L"Sở thích 1: không có.\n");
		wprintf(L"Sở thích 2: không có.\n");
	}
	if (sothich[n - 1] == 1)
	{
		wprintf(L"Sở thích 1: %ls\n", b[n - 1].sothich1);
		wprintf(L"Sở thích 2: không có.\n");
	}
	if (sothich[n - 1] == 2)
	{
		wprintf(L"Sở thích 1: %ls\n", b[n - 1].sothich1);
		wprintf(L"Sở thích 2: %ls\n", b[n - 1].sothich2);
	}
}
void tuychonxuat(Sinhvien* a, int sodong, int& n, int* sothich)
{
	wprintf(L"Vui lòng nhập số thứ tự sinh viên cần phát sinh trang profile page, nhập 0 để xuất tất cả, nhập -1 để thoát: ");
	do
	{
		wscanf(L"%d", &n);
		if (n<-1 || n>sodong)
		{
			wprintf(L"Nhập không hợp lệ, vui lòng nhập lại: ");
			continue;
		}
		if (n == 0)
		{
			for (int i = 0; i < sodong; i++)
			{
				xuatfile(a, i, sothich);
			}
			wprintf(L"Vui lòng nhập tiếp tùy chọn: ");
			continue;
		}
		if (n == -1)
		{
			return;
		}
		xuatfile(a, n - 1, sothich);
		wprintf(L"Vui lòng nhập tiếp tùy chọn: ");
	} while (1);
}
void main()
{

	_setmode(_fileno(stdout), _O_U16TEXT);
	Sinhvien a;
	Sinhvien *b = NULL;
	int* sothich = NULL;
	int sosothich;
	FILE* fp = _wfopen(L"DS_SinhVien.csv", L"rt, ccs= UTF-8");
	if (fp == NULL)
	{
		wprintf(L"ERROR!.\n");
		return;
	}
	int n = linecount(fp);
	b = new Sinhvien[n];
	sothich = new int[n];
	rewind(fp);
	for (int i = 1; i <= n; i++)
	{
		sosothich = 0;
		docfile(fp, a, sosothich);
		b[i - 1] = a;
		sothich[i - 1] = sosothich;

	}
	for (int i = 1; i <= n; i++)
	{
		info(b, i, sothich);
	}
	int x;
	tuychonxuat(b, n, x, sothich);
	delete[]b;
	delete[]sothich;
	fclose(fp);

}


