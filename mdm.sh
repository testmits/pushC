#!/bin/bash

echo ""
echo -e "Bypass MDM"
echo ""
echo -e "Bypass on Recovery"

# Đổi tên thư mục Data nếu tồn tại
if [ -d "/Volumes/Macintosh HD - Data" ]; then
  diskutil rename "Macintosh HD - Data" "Data"
fi

# Thiết lập thông tin người dùng mặc định
realName="${realName:=Macbook}"
username="${username:=macbook}"
passw="${passw:=1234}"

# Đường dẫn tới dslocal
dscl_path='/Volumes/Data/private/var/db/dslocal/nodes/Default' 

# Tạo người dùng
echo -e "Đang tạo user"
dscl -f "$dscl_path" localhost -create "/Local/Default/Users/$username"
dscl -f "$dscl_path" localhost -create "/Local/Default/Users/$username" UserShell "/bin/zsh"
dscl -f "$dscl_path" localhost -create "/Local/Default/Users/$username" RealName "$realName"
dscl -f "$dscl_path" localhost -create "/Local/Default/Users/$username" UniqueID "501"
dscl -f "$dscl_path" localhost -create "/Local/Default/Users/$username" PrimaryGroupID "20"

# Tạo thư mục người dùng
mkdir -p "/Volumes/Data/Users/$username"

# Cấu hình đường dẫn NFSHomeDirectory và đặt mật khẩu
dscl -f "$dscl_path" localhost -create "/Local/Default/Users/$username" NFSHomeDirectory "/Users/$username"
dscl -f "$dscl_path" localhost -passwd "/Local/Default/Users/$username" "$passw"

# Thêm người dùng vào nhóm admin
dscl -f "$dscl_path" localhost -append "/Local/Default/Groups/admin" GroupMembership $username

# Chặn host
echo "0.0.0.0 deviceenrollment.apple.com" >> /Volumes/Macintosh\ HD/etc/hosts
echo "0.0.0.0 mdmenrollment.apple.com" >> /Volumes/Macintosh\ HD/etc/hosts
echo "0.0.0.0 iprofiles.apple.com" >> /Volumes/Macintosh\ HD/etc/hosts
echo -e "Chặn host thành công"

# Xóa cấu hình
touch /Volumes/Data/private/var/db/.AppleSetupDone

# Tắt SIP
csrutil disable

# Xóa các tệp cấu hình
rm -rf /Volumes/Macintosh\ HD/var/db/ConfigurationProfiles/Settings/.cloudConfigHasActivationRecord
rm -rf /Volumes/Macintosh\ HD/var/db/ConfigurationProfiles/Settings/.cloudConfigRecordFound
rm -rf /Volumes/Macintosh\ HD/var/db/ConfigurationProfiles/Settings/.cloudConfigRecordNotFound

# Tạo các tệp để đảm bảo rằng cấu hình đã được xóa
touch /Volumes/Macintosh\ HD/var/db/ConfigurationProfiles/Settings/.cloudConfigProfileInstalled

# Kích hoạt lại SIP
csrutil enable

echo -e "Remove config profile thành công"
echo "----------------------"
